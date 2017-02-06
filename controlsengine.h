#ifndef CONTROLSENGINE_H
#define CONTROLSENGINE_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class QPushButton;
class ControlsEngine : public QWidget
{
public:
    explicit ControlsEngine( QWidget *parent = 0 );
    ControlsEngine::ControlsEngine( int number_of_digits );
    QPushButton *ControlsEngine::CreateButton(QString button_title);
    QLayout* ControlsEngine::getLayout();


     QHBoxLayout *gui_layout;
};

#endif // CONTROLSENGINE_H
