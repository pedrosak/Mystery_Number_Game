#ifndef CONTROLSENGINE_H
#define CONTROLSENGINE_H

#include <QWidget>
#include <QPushButton>

class QPushButton;
class ControlsEngine : public QWidget
{
public:
    explicit ControlsEngine( QWidget *parent = 0 );
    QPushButton *ControlsEngine::CreateButton( QString button_title, int button_id );
};

#endif // CONTROLSENGINE_H
