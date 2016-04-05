#ifndef QHTTP_H
#define QHTTP_H

#include <QtWidgets/QWidget>
#include "ui_qhttp.h"
#include "HttpOperator.h"

class QHttp1 : public QWidget
{
	Q_OBJECT

public:
	QHttp1(QWidget *parent = 0);
	~QHttp1();

private slots:
	void slotLoginResule();

private:
	Ui::QHttpClass ui;
	HttpOperator* m_pHttp;
};

#endif // QHTTP_H
