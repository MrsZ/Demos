//
// Created by kestiny on 2015/11/14.
//

#ifndef QTDEMO_WIDGET_H
#define QTDEMO_WIDGET_H

#include <QWidget>
#include "ui_widget.h"

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget();
    ~Widget();

private slots:
    void slotPushbutton();

private:
    Ui::Widget ui;
};


#endif //QTDEMO_WIDGET_H
