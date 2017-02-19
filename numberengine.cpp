#include "numberengine.h"

#define highNumber 9
#define lowNumber 0

// Constructor
NumberEngine::NumberEngine(void)
{
    qDebug() << " Number Engine Starting Up... vrooom";
}


// Destructor
NumberEngine::~NumberEngine(void)
{
    // Delete Resources
}

// Generates a random number of a specific size
void NumberEngine::randomNumberGenerator( int digit_size )
{
    setWorkingDigit( digit_size );
    // Check if digit_size is between 4 and 6
    if ( digit_size < 4 || digit_size > 6 )
    {
        qDebug  () << " Digit size is out-of-range.";
    }
    else
    {
        // Generated qrand() seed
         qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);

        // Generate Random Number
        for( int count_digit_size = 0; count_digit_size < digit_size; count_digit_size++ )
        {
                digit = qrand() % highNumber + lowNumber;
                generated_number += QString("%1").arg(digit);
        }
//        qDebug() <<  digit_size;
        qDebug() << generated_number;
//        qDebug() << generated_number.size();

    }
}

// Get the digit at a specify location
QString NumberEngine::getDigitAt( int digit_location )
{
    // Check if digit_locatin is within range of generated_number
    if ( digit_location <= generated_number.size() && digit_location >= 0 )
    {
        qDebug() << generated_number.at(digit_location);
        return generated_number.at( digit_location );
    }

    return 0;
}

// Returns a pointer to the generated number string
QString* NumberEngine::getGeneratedNumber()
{
    return &generated_number;
}

// Sets the current working digit
void NumberEngine::setWorkingDigit( int digit_size )
{

    if( current_working_digit < digit_size )
    {
        current_working_digit  += 1;
    }
    else
    {
        qDebug() << "Current working digit exceeds RNG digit quantity.";
    }
}

// Returns the current working digit
inline int NumberEngine::getWorkingDigit()
{
    return current_working_digit;
}

void handleButton(QString &button_title)
{
    qDebug() << "Hey" + button_title;
}

//// Slot for the up button. Calls the CounterUp function to add one to the current counter
//void NumberEngine::handleButton_up(QList<QLabel *> label_list)
//{
//    label_list.at( getWorkingDigit() )->setText( CounterUp() );
//}

//// Slot for the down button. Calls the COunterDown function to subtract one from the current counter
//void NumberEngine::handleButton_down(QList<QLabel *> label_list)
//{
//    label_list.at( getWorkingDigit() )->setText( CounterDown() );
//}


//// Slot for the submit button. Checks current counter against the generated RN.
//void NumberEngine::handleButton_submit(QList<QLabel *> label_list)
//{
//    if (label_list.at( getWorkingDigit() )->text() == generated_number.at( getWorkingDigit() ) )
//    {
//        // Changes color of correct number to green.
//        // Future work will be to make a function out of this.
//        QPalette* palette = new QPalette();
//        palette->setColor(QPalette::WindowText,Qt::green);
//        label_list.at( getWorkingDigit() )->setPalette( *palette);

//        // If its the last digit end the game.
//        if ( getWorkingDigit() == ( label_list.size() - 1) )
//        {
//            qDebug() << " Game won!";
//            exit(1);
//        }
//        else
//        {
//            input_counter = 0;
//            setWorkingDigit( label_list.size() - 1 );
//        }
//    }
//}

// Counts Up
QString NumberEngine::CounterUp()
{
    if ( input_counter >= 0 && input_counter < 9)
    {
        input_counter += 1;
    }
    else
    {
        input_counter = 0;
    }
    return QString::number( input_counter );
}

// Counts Down
QString NumberEngine::CounterDown()
{
    if ( input_counter > 0 && input_counter <= 9)
    {
        input_counter -= 1;
    }
    else
    {
        input_counter = 9;
    }
    return QString::number( input_counter );
}
