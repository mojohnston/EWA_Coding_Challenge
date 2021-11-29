#include "udpreceive.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UDPReceive w;
    w.setFixedSize(491,474);
    w.setWindowTitle("Coding Challenge 3");
    w.show();
    return a.exec();
}
