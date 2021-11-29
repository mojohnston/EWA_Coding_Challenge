#include "udpreceive.h"
#include "ui_udpreceive.h"
#include <string>
#include <QDebug>
#include <QtWidgets>
#include <QMessageBox>

UDPReceive::UDPReceive(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UDPReceive)
{
    ui->setupUi(this);

    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost,1234);
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));

}

UDPReceive::~UDPReceive()
{
    delete ui;
}

void UDPReceive::readyRead()
{
    /*
     * Similar to the serial port message, the UDP message is received and split,
     * then saved under their respective variables.
     */
    QByteArray Buffer;
    Buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;
    socket->readDatagram(Buffer.data(),Buffer.size(), &sender, &senderPort);

    QString DataAsString = QString(Buffer);
    QStringList buffer_split = DataAsString.split(",");
    QString parsed_data0 = buffer_split[0];
    QString parsed_data1 = buffer_split[1];
    QString parsed_data2 = buffer_split[2];
    QString parsed_data3 = buffer_split[3];
    double resistance_value = parsed_data0.toDouble();
    double humidity_value = parsed_data1.toDouble();
    double temperatureF_value = parsed_data2.toDouble();
    double temperatureC_value = parsed_data3.toDouble();

    UDPReceive::updateTempC(temperatureC_value);
    UDPReceive::updateTempF(temperatureF_value);
    UDPReceive::updateHumidity(humidity_value);
    UDPReceive::updateResistance(resistance_value);

}

/*
 * update the values shown in the UI to the updated values received via UDP
 */

void UDPReceive::updateTempC(double UdpMessageVal)
{
    ui->tempCVal->display(UdpMessageVal);
}

void UDPReceive::updateTempF(double UdpMessageVal)
{
    ui->tempFVal->display(UdpMessageVal);
}

void UDPReceive::updateHumidity(double UdpMessageVal)
{
    ui->humVal->display(UdpMessageVal);
}

void UDPReceive::updateResistance(double UdpMessageVal)
{
    ui->resVal->display(UdpMessageVal);
}

