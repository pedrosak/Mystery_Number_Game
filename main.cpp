#include "mainwindow.h"
#include "numberengine.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    NumberEngine numberEngine;
    numberEngine.randomNumberGenerator(4);
    numberEngine.randomNumberGenerator(-7);
        numberEngine.randomNumberGenerator(0);
    return a.exec();
}
