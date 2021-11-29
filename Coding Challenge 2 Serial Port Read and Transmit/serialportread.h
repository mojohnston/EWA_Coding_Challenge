#ifndef SERIALPORTREAD_H
#define SERIALPORTREAD_H

#include <QDialog>
#include <QSerialPort>
#include <QByteArray>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class SerialPortRead; }
QT_END_NAMESPACE

class SerialPortRead : public QDialog
{
    Q_OBJECT

public:
    SerialPortRead(QWidget *parent = nullptr);
    ~SerialPortRead();

private slots:
    void readSerial();

public slots:

private:
    Ui::SerialPortRead *ui;
    QSerialPort *arduino;
    QUdpSocket *socket;

    static const quint16 arduino_nano_vendor_id = 6790;
    static const quint16 arduino_nano_product_id = 29987;

    QByteArray serialData;
    QString serialBuffer;
    QString parsed_data0;
    QString parsed_data1;
    QString parsed_data2;
    QString parsed_data3;

    // QString arduino_port_name;
    // bool arduino_is_available;

    double temperatureC_value;
    double temperatureF_value;
    double humidity_value;
    double resistance_value;

};
#endif // SERIALPORTREAD_H
