#include "controlsengine.h"
#include "mainwindow.h"


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

    // Create the control buttons
    QPushButton *button_up = new QPushButton ( "Up", this );
    QPushButton *button_down = new QPushButton ( "Down", this );
    QPushButton *button_submit = new QPushButton ( "Submit", this );

    connect( signalMapper, SIGNAL( mapped (QString ) ) , &numEngine, SIGNAL( handleButton(QString) ));
//    button_layout->setSpacing( 0 );
//    button_layout->setMargin( 0 );
    button_layout->addWidget( button_up, 0, Qt::AlignHCenter );
    button_layout->addWidget( button_down, 0, Qt::AlignHCenter );
    button_layout->addWidget( button_submit, 0, Qt::AlignHCenter);

    gui_layout->addLayout( button_layout);

}

// Create a button and return a pointer to said button
// Current version does not use this function.
QPushButton* ControlsEngine::CreateButton( QString button_title, QString button_name )
{
        QPushButton *button = new QPushButton( button_title, this );
        button->setObjectName( button_name );

        connect( button, SIGNAL( clicked() ), signalMapper, SLOT( map() ) );
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
