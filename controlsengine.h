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

signals:
     void redirectData_up( QList<QLabel*> ) ;
     void redirectData_down( QList<QLabel*> ) ;
     void redirectData_submit( QList<QLabel*> ) ;

public slots:
     void sendLabelList_up(){ emit redirectData_up( label_list );}
     void sendLabelList_down(){ emit redirectData_down( label_list );}
     void sendLabelList_submit(){ emit redirectData_submit( label_list );}

};

#endif // CONTROLSENGINE_H
