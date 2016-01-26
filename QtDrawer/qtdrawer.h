#ifndef QTDRAWER_H
#define QTDRAWER_H

#include <QMainWindow>
#include "ui_qtdrawer.h"
#include "DrawAreaWidget.h"

class QtDrawer : public QMainWindow
{
	Q_OBJECT

public:
	QtDrawer(QWidget *parent = 0);
	~QtDrawer();

private slots:
	void slotDoubleUnSigned(QListWidgetItem* item);
	void slotDoubleSigned(QListWidgetItem* item);
	void slotSave();
	void slotExit();
	void slotColorSelect();
	void slotReDraw();

private:
	void initList();

public:
	Ui::QtDrawerClass ui;
	DrawAreaWidget* m_pDraw;
	QString m_strCurrentFile;
};

#endif // QTDRAWER_H
