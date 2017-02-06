#include "controlsengine.h"
#include <QDebug>

ControlsEngine::ControlsEngine( QWidget *parent) :
    QWidget( parent )
{
    qDebug() << " Controls Engine Starting Up... vrooom";
}


QPushButton* ControlsEngine::CreateButton( QString button_title, int button_id )
{
        QPushButton *button = new QPushButton( button_title, this );

        return button;
}
