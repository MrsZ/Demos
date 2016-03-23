#include "ffmpegdemo.h"
#include <QDateTime>

FFMpegDemo::FFMpegDemo(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_pScreenRecord = NULL;

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(slotStart()));
	connect(ui.pushButtonEnd, SIGNAL(clicked()), this, SLOT(slotEnd()));
}

FFMpegDemo::~FFMpegDemo()
{

}

void FFMpegDemo::slotStart()
{
	if (m_pScreenRecord == NULL)
	{
		m_pScreenRecord = new ScreenRecord;
	}
	QDateTime time = QDateTime::currentDateTime();
	QString strName = time.toString("yyyyMMddhhmmss");
	QString strPath = QString("D:/project/temp/");
	m_pScreenRecord->setOutFileName(strPath.append(strName));
	m_pScreenRecord->setFrameRate(ui.spinBox->value());
	m_pScreenRecord->setVedioFormat(ui.lineEdit->text());
	m_pScreenRecord->begin();
}

void FFMpegDemo::slotEnd()
{
	if (m_pScreenRecord)
	{
		m_pScreenRecord->end();
	}
}

void FFMpegDemo::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Q)
	{
		if (m_pScreenRecord)
		{
			m_pScreenRecord->end();
		}
	}
}
