#include "mainwindow.h"
#include "numberengine.h"

#include <QApplication>
#include <QInputDialog>
#include <QHBoxLayout>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    NumberEngine numberEngine;
    QHBoxLayout *digitLayout = new QHBoxLayout;

    QLabel *digit_one = new QLabel;
    QLabel *digit_two = new QLabel;
    QLabel *digit_three = new QLabel;
    QLabel *digit_four = new QLabel;

    numberEngine.randomNumberGenerator( 4 );

    digit_one->setText( numberEngine.getDigitAt( 0 ));
    digit_two->setText( numberEngine.getDigitAt( 1 ));
    digit_three->setText( numberEngine.getDigitAt( 2 ));
    digit_four->setText( numberEngine.getDigitAt( 3 ));

    digitLayout->addWidget( digit_one );
    digitLayout->addWidget( digit_two );
    digitLayout->addWidget( digit_three );
    digitLayout->addWidget( digit_four );

    MainWindow w;
    w.centralWidget()->setLayout( digitLayout );
    w.show();

    return a.exec();
}
