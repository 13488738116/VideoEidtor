#include "mainwindow.h"
#include"global.h"
#include <QApplication>
#include"videopreview.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
