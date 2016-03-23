//
// File: ScreenRecord.h
// Author:lyk
// Date: 2016/03/23
// Desc: 利用FFMPEG进行屏幕的录制
//
#ifndef SCREENRECORD_H
#define SCREENRECORD_H

#include <QProcess>

class ScreenRecord
{
public:
	ScreenRecord();
	~ScreenRecord();

	// 设置帧率，默认60帧
	void setFrameRate(int rate = 60);
	// 分辨率，默认为屏幕大小
	void setResolution(int width, int height);
	// 输出文件及路径
	void setOutFileName(const QString& strName);
	// 输出视频格式，默认avi
	void setVedioFormat(const QString& strFormat = ".avi");

	void begin();
	void end();

private:
	int m_iFrameRate;
	int m_iWidth;
	int m_iHeight;
	QString m_strFileName;
	QString m_strFormat;
	QProcess* m_pProcess;
};

#endif // SCREENRECORD_H
