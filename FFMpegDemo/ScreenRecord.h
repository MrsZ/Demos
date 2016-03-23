//
// File: ScreenRecord.h
// Author:lyk
// Date: 2016/03/23
// Desc: ����FFMPEG������Ļ��¼��
//
#ifndef SCREENRECORD_H
#define SCREENRECORD_H

#include <QProcess>

class ScreenRecord
{
public:
	ScreenRecord();
	~ScreenRecord();

	// ����֡�ʣ�Ĭ��60֡
	void setFrameRate(int rate = 60);
	// �ֱ��ʣ�Ĭ��Ϊ��Ļ��С
	void setResolution(int width, int height);
	// ����ļ���·��
	void setOutFileName(const QString& strName);
	// �����Ƶ��ʽ��Ĭ��avi
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
