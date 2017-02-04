#ifndef NUMBERENGINE_H
#define NUMBERENGINE_H

#include <QDebug>
#include <QString>
#include <QDateTime>


class NumberEngine
{
public:
    NumberEngine(void);
    ~NumberEngine(void);
    void NumberEngine::randomNumberGenerator( int digit_size );
    QString NumberEngine::getDigitAt( int digit );

private:
    QString generated_number;
    int digit;
};

#endif // NUMBERENGINE_H
