#ifndef CONTROLSENGINE_H
#define CONTROLSENGINE_H

#include "numberengine.h"

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>
#include <QLabel>
#include <QList>
#include <QVBoxLayout>
#include <QSignalMapper>

class QPushButton;
class ControlsEngine : public QWidget
{
    Q_OBJECT
public:
    explicit ControlsEngine( QWidget *parent = 0 );
    ControlsEngine::ControlsEngine( int number_of_digits );
    QPushButton *ControlsEngine::CreateButton(QString button_title, QString button_name);
    QLayout* ControlsEngine::getLayout();
     QHBoxLayout *gui_layout;
     NumberEngine numEngine;
    QList <QLabel *>   label_list;

     QList <QLabel *> ControlsEngine::getLabelList();

    QSignalMapper *signalMapper = new  QSignalMapper( this );

};

#endif // CONTROLSENGINE_H
