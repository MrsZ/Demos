#ifndef FFMPEGDEMO_H
#define FFMPEGDEMO_H

#include <QtWidgets/QWidget>
#include "ui_ffmpegdemo.h"
#include "ScreenRecord.h"
#include <QKeyEvent>

class FFMpegDemo : public QWidget
{
	Q_OBJECT

public:
	FFMpegDemo(QWidget *parent = 0);
	~FFMpegDemo();

protected:
	virtual void keyPressEvent(QKeyEvent* event);

private slots:
	void slotStart();
	void slotEnd();

private:
	Ui::FFMpegDemoClass ui;
	ScreenRecord* m_pScreenRecord;
};

#endif // FFMPEGDEMO_H
