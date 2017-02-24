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


class ControlsEngine : public QWidget
{
    Q_OBJECT
public:
    explicit ControlsEngine( QWidget *parent = 0 );
    ControlsEngine::ControlsEngine( int number_of_digits );
    QPushButton *ControlsEngine::CreateButton(QString button_title);
    QLayout* ControlsEngine::getLayout();
    QList <QLabel *> ControlsEngine::getLabelList();
    QHBoxLayout *gui_layout;
    QList <QLabel *>   label_list;
    QSignalMapper *signalMapper = new  QSignalMapper( this );

    enum ButtonNameHash ControlsEngine::decodeButtonName( QString button_name );

public slots:
     void handelButton(QString button );
};

#endif // CONTROLSENGINE_H
