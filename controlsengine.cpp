#include "controlsengine.h"
#include "numberengine.h"
#include "mainwindow.h"

#include <QDebug>
#include <QLabel>
#include <QList>

#include <QVBoxLayout>

// Constructor
ControlsEngine::ControlsEngine( QWidget *parent) :
    QWidget( parent )
{
    qDebug() << " Controls Engine Starting Up... vrooom";

}

// Constructor with input to the number of digits to generate a random number with
ControlsEngine::ControlsEngine( int number_of_digits )
{
    qDebug() << " Controls Engine Starting Up... vrooom";

    NumberEngine numEngine;
    numEngine.randomNumberGenerator( number_of_digits );

     gui_layout = new QHBoxLayout;

     QVBoxLayout *button_layout = new QVBoxLayout;

    QList <QLabel *>   label_list;

    // Create a label for each digit of the RNG
    for ( int count_digits = 0; count_digits < number_of_digits; count_digits++ )
    {
       label_list << new QLabel(this);
       label_list.at( count_digits )->setText(  numEngine.getDigitAt( count_digits ));
       gui_layout->addWidget( label_list.at( count_digits ));
    }

    // Create the control buttons
    button_layout->addWidget( CreateButton( "Up") );
    button_layout->addWidget( CreateButton( "Submit") );
    button_layout->addWidget( CreateButton( "Down") );

    gui_layout->addLayout( button_layout );

}

// Create a button and return a pointer to said button
QPushButton* ControlsEngine::CreateButton( QString button_title )
{
        QPushButton *button = new QPushButton( button_title, this );

        return button;
}

// Return pointer to layout created in constructor
QLayout* ControlsEngine::getLayout()
{
    return gui_layout;
}
