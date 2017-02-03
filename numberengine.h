#ifndef NUMBERENGINE_H
#define NUMBERENGINE_H

#include "QDebug"
#include "QString"
#include "stdlib.h"

class NumberEngine
{
public:
    NumberEngine(void);
    ~NumberEngine(void);
    void NumberEngine::randomNumberGenerator( int digit_size );
};

#endif // NUMBERENGINE_H
