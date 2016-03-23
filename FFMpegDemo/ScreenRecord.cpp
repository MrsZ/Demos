#include "ScreenRecord.h"
#include <QApplication>
#include <QDesktopWidget>

ScreenRecord::ScreenRecord()
{
	m_iFrameRate = 60;
	QRect rect = QApplication::desktop()->availableGeometry();
	m_iWidth = rect.width();
	m_iHeight = rect.height();
	m_strFormat = ".avi";

	m_pProcess = NULL;
}

ScreenRecord::~ScreenRecord()
{
	m_pProcess = NULL;
}

void ScreenRecord::setFrameRate(int rate /*= 60*/)
{
	m_iFrameRate = rate;
}

void ScreenRecord::setResolution(int width, int height)
{
	m_iWidth = width;
	m_iHeight = height;
}

void ScreenRecord::setOutFileName(const QString& strName)
{
	m_strFileName = strName;
}

void ScreenRecord::setVedioFormat(const QString& strFormat /*= ".avi"*/)
{

}

void ScreenRecord::begin()
{
	if (m_strFileName.isEmpty())
	{
		return;
	}
	if (m_pProcess == NULL)
	{
		m_pProcess = new QProcess();
	}

	QString str = QString("ffmpeg.exe -f gdigrab -framerate %1 -offset_x %2 -offset_y %3 -video_size %4x%5 -i desktop %6")
		.arg(m_iFrameRate).arg(0).arg(0).arg(m_iWidth).arg(m_iHeight).arg(m_strFileName).append(m_strFormat);

	m_pProcess->start(str);
}

void ScreenRecord::end()
{
	if (m_pProcess)
	{
		m_pProcess->write("q");
	}
}
