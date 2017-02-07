#include "mainwindow.h"
#include "controlsengine.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ControlsEngine controlEngine( 4 );

    MainWindow w;

    w.setWindowTitle( "Mystery Number Game" );
    w.centralWidget()->setLayout( controlEngine.getLayout() );
    w.show();

    return a.exec();
}
