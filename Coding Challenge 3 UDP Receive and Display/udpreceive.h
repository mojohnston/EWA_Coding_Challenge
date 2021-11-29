#ifndef UDPRECEIVE_H
#define UDPRECEIVE_H

#include <QDialog>
#include <QByteArray>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class UDPReceive; }
QT_END_NAMESPACE

class UDPReceive : public QDialog
{
    Q_OBJECT

public:
    UDPReceive(QWidget *parent = nullptr);
    ~UDPReceive();

private slots:
    void updateTempC(double);
    void updateTempF(double);
    void updateHumidity(double);
    void updateResistance(double);

public slots:
    void readyRead();

private:
    Ui::UDPReceive *ui;
    QUdpSocket *socket;

};
#endif // DIALOG_H

