#ifndef DOWMLOAD_H
#define DOWMLOAD_H

#include <QtGui/QWidget>
#include "ui_dowmload.h"

class DowmLoad : public QWidget
{
	Q_OBJECT

public:
	DowmLoad(QWidget *parent = 0, Qt::WFlags flags = 0);
	~DowmLoad();

private:
	Ui::DowmLoadClass ui;
};

#endif // DOWMLOAD_H
