#include "serialportread.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SerialPortRead w;
    w.setFixedSize(491,91);
    w.setWindowTitle("Coding Challenge 2");
    w.show();
    return a.exec();
}
