#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setFixedSize(557,471);
    w.setStyleSheet("QPushButton{height:28;width:93}");
    return a.exec();
}
