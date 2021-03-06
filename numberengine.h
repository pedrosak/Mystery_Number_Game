#ifndef NUMBERENGINE_H
#define NUMBERENGIN1E_H

#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QLabel>


class NumberEngine : public QObject
{
    Q_OBJECT
    friend class ControlsEngine;

public:
    NumberEngine(void);
    ~NumberEngine(void);
    void NumberEngine::randomNumberGenerator( int digit_size );
    QString NumberEngine::getDigitAt( int digit );
    QString* NumberEngine::getGeneratedNumber();
    void NumberEngine::setWorkingDigit( int digit_size );
    QString NumberEngine::CounterUp();
    QString NumberEngine::CounterDown();

protected:
    QString generated_number;
    int digit;
    int current_working_digit =-1;
    int input_counter = 0;
};

#endif // NUMBERENGINE_H
