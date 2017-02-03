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


void NumberEngine::randomNumberGenerator( int digit_size )
{
    // Check if digit_size is between 4 and 6
    if ( digit_size < 4 || digit_size > 6 )
    {
        qDebug  () << " Digit size is out-of-range.";
    }
    else
    {
        // Generated Number
        QString generated_number;

        // Generate Random Number
        for( int count_digit_size = 0; count_digit_size < digit_size; count_digit_size++ )
        {
                int digit = qrand() % highNumber + lowNumber;
                generated_number += QString("%1").arg(digit);
        }

        qDebug() <<  digit_size;
        qDebug() << generated_number;
    }
}

