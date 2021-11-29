#include "serialportread.h"
#include "ui_serialportread.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <string>
#include <QDebug>
#include <QtWidgets>
#include <QMessageBox>

SerialPortRead::SerialPortRead(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SerialPortRead)
{
    /*
     * Binding to PORT 1234 for sending UDP message
     */
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost,1234);
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));

    ui->setupUi(this);

    bool arduino_is_available = false;
    QString arduino_port_name = "";
    arduino = new QSerialPort(this);
    serialBuffer = "";

    /*
     *The following code is used to determine the arduino vendor ID and product ID
     *It is only needed on first use of arduino, but values remain unchanged after discovery
     *
    qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo & serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
        if(serialPortInfo.hasVendorIdentifier()){
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
        }
        qDebug() << "Has product ID: " << serialPortInfo.hasProductIdentifier();
        if(serialPortInfo.hasProductIdentifier()){
            qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
        }
    }
    */


    /*
     * searching through ports to find one with correct product and vendor ids
    */
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == arduino_nano_vendor_id){
                if(serialPortInfo.productIdentifier() == arduino_nano_product_id){
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_available = true;
                }
            }
        }
    }

    if(arduino_is_available){
        // open and configure the serialport
        qDebug() << "Found the arduino port...\n";
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::ReadOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
    }else{
        qDebug() << "Couldn't find the correct port for the arduino.\n";
        QMessageBox::information(this, "Serial Port Error", "Couldn't find the Arduino!");
    }


}

SerialPortRead::~SerialPortRead()
{
    if(arduino->isOpen()){
        arduino->close();
    }
    delete ui;
}

void SerialPortRead::readSerial()
{
    /*
     * readyRead() doesn't guarantee that the entire message will be received all at once.
     * The message can arrive split into parts.  Need to buffer the serial data and then parse for the temperature value.
     *
     */
    QStringList buffer_split = serialBuffer.split(","); //  split the serialBuffer string, parsing with ',' as the separator

    //  Check to see if there less than 4 tokens in buffer_split.
    if(buffer_split.length() < 4){
        // no parsed value yet so continue accumulating bytes from serial in the buffer.
        serialData = arduino->readAll();
        serialBuffer = serialBuffer + QString::fromStdString(serialData.toStdString());
        serialData.clear();
    }else{
        /*
         * data received, so now we save the arduino data to variables for each pot resistance, temperatures, and humidity
         * then we create a data array and send this in a UDP message to a specific port
         */
        serialBuffer = "";
        parsed_data0 = buffer_split[0];
        parsed_data1 = buffer_split[1];
        parsed_data2 = buffer_split[2];
        parsed_data3 = buffer_split[3];
        temperatureC_value = parsed_data0.toDouble();
        temperatureF_value = parsed_data1.toDouble();
        humidity_value = parsed_data2.toDouble();
        resistance_value = parsed_data3.toDouble();

        QByteArray Data;
        Data.insert(0, parsed_data0.toLocal8Bit());
        Data.insert(0, ",");
        Data.insert(0, parsed_data1.toLocal8Bit());
        Data.insert(0, ",");
        Data.insert(0, parsed_data2.toLocal8Bit());
        Data.insert(0, ",");
        Data.insert(0, parsed_data3.toLocal8Bit());
        socket->writeDatagram(Data,QHostAddress::LocalHost,1234); //send UDP message with data acquired from serial port

    }
}
