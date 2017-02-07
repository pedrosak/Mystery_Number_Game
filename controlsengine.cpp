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
    // connecting of each button were implemented using tivial solution. Three different slots and signals for each button.
    // Further work will be to have a signle signal/slot maping function
    QPushButton *button_up = new QPushButton ( "Up", this );
    connect( button_up, SIGNAL ( released() ), this, SLOT ( sendLabelList_up() ));
    connect( this, SIGNAL ( redirectData_up( QList<QLabel*> )), &numEngine, SLOT ( handleButton_up( QList<QLabel*> )));

    QPushButton *button_down = new QPushButton ( "Down", this );
    connect( button_down, SIGNAL ( released() ), this, SLOT ( sendLabelList_down() ));
    connect( this, SIGNAL ( redirectData_down( QList<QLabel*> )), &numEngine, SLOT ( handleButton_down( QList<QLabel*> )));

    QPushButton *button_submit = new QPushButton ( "Submit", this );
    connect( button_submit, SIGNAL ( released() ), this, SLOT ( sendLabelList_submit() ));
    connect( this, SIGNAL ( redirectData_submit( QList<QLabel*> )), &numEngine, SLOT ( handleButton_submit( QList<QLabel*> )));

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
        connect( button, SIGNAL ( released()), this, SLOT ( sendLabelList() ));
        connect( this, SIGNAL ( redirectData( QList<QLabel*> ) ), &numEngine, SLOT ( handleButton( QList<QLabel*> ) ));

        return button;
}

// Return pointer to layout created in constructor
QLayout* ControlsEngine::getLayout()
{
    return gui_layout;
}

