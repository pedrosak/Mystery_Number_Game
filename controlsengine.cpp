#include "controlsengine.h"
#include "mainwindow.h"

#define NUMBER_OF_BUTTONS 3

NumberEngine numEngine;


enum ButtonNameHash {
    Up = 1,
    Down ,
    Submit,
    Other,
};

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

     numEngine.randomNumberGenerator( number_of_digits );

     gui_layout = new QHBoxLayout;

     QVBoxLayout *button_layout = new QVBoxLayout;

    // Create a label for each digit of the RNG
    for ( int count_digits = 0; count_digits < number_of_digits; count_digits++ )
    {
       label_list << new QLabel(this);
       QFont font = label_list.at( count_digits )->font();
       font.setPointSize( 80 );
       font.setBold( false );
       label_list.at( count_digits )->setFont( font );
       label_list.at( count_digits )->setText(  "0" );

       gui_layout->addWidget( label_list.at( count_digits ));
    }

     connect( signalMapper, SIGNAL( mapped (QString ) ) , this, SLOT( handelButton( QString ) ));
    // Create the control buttons
    QPushButton *button_up = CreateButton("Up");
    QPushButton *button_down = CreateButton("Down");
    QPushButton *button_submit = CreateButton("Submit");

//    button_layout->setSpacing( 0 );
//    button_layout->setMargin( 0 );

    button_layout->addWidget( button_up, 0, Qt::AlignHCenter );
    button_layout->addWidget( button_down, 0, Qt::AlignHCenter );
    button_layout->addWidget( button_submit, 0, Qt::AlignHCenter);

    gui_layout->addLayout( button_layout);
}

// Create a button and return a pointer to said button
// Current version does not use this function.
QPushButton* ControlsEngine::CreateButton( QString button_title )
{
        QPushButton *button = new QPushButton( button_title, this );
        button->setObjectName( button_title );

        connect( button, SIGNAL( released() ), signalMapper, SLOT( map() ) );
        signalMapper->setMapping( button, button_title );

        return button;
}

// Return pointer to layout created in constructor
QLayout* ControlsEngine::getLayout()
{
    return gui_layout;
}

QList<QLabel *> ControlsEngine::getLabelList()
{
    return label_list;
}

void ControlsEngine::handelButton( QString button )
{
    switch ( ControlsEngine::decodeButtonName( button )) {
    case 1:
        label_list.at( numEngine.current_working_digit )->setText( numEngine.CounterUp() );
        break;
    case 2:
        label_list.at( numEngine.current_working_digit )->setText( numEngine.CounterDown() );
        break;
    case 3:
        if (label_list.at( numEngine.current_working_digit )->text() == numEngine.generated_number.at( numEngine.current_working_digit ) )
            {
                // Changes color of correct number to green.
                // Future work will be to make a function out of this.
                QPalette* palette = new QPalette();
                palette->setColor(QPalette::WindowText,Qt::green);
                label_list.at( numEngine.current_working_digit )->setPalette( *palette);

                // If its the last digit end the game.
                if ( numEngine.current_working_digit == ( label_list.size() - 1) )
                {
                    qDebug() << " Game won!";
                    exit(1);
                }
                else
                {
                  numEngine.input_counter = 0;
                  numEngine.setWorkingDigit( label_list.size() - 1 );
                }
            }
        break;
    default:
        qDebug () << "You pressed other than Up";
        break;
    }
}

ButtonNameHash ControlsEngine::decodeButtonName( QString button_name )
{
    if ( button_name == "Up")
    {
        return Up;
    } else if ( button_name == "Down" ) {
        return Down;
    } else if ( button_name == "Submit" ) {
        return Submit;
    } else
        return Other;
}
