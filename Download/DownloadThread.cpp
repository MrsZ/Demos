#include "DownloadThread.h"

DownloadThread::DownloadThread(QObject *parent)
	: QThread(parent)
{
	m_pFtp = new FtpCurl;
	m_bDown = true;
}

DownloadThread::~DownloadThread()
{
	delete m_pFtp;
}

void DownloadThread::run()
{
	if (m_bDown)
	{
		m_pFtp->downLoad(m_strFtpPath, m_strLocalPath);
	}
	else
	{
		m_pFtp->upLoad(m_strFtpPath, m_strLocalPath);
	}
}

void DownloadThread::downLoad( const std::string& ftpPath, const std::string& localPath, bool isDown )
{
	m_bDown = isDown;
	m_strFtpPath = ftpPath;
	m_strLocalPath = localPath;
}
