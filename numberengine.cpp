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
        qDebug() << generated_number;
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
