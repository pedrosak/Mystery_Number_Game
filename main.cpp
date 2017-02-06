#include "mainwindow.h"
#include "controlsengine.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ControlsEngine controlEngine( 5 );

    MainWindow w;

    w.centralWidget()->setLayout( controlEngine.getLayout() );
    w.show();

    return a.exec();
}
