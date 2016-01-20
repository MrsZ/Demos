#include "DownloadThread.h"

DownloadThread::DownloadThread(QObject *parent)
	: QThread(parent)
{
	m_pFtp = new FtpCurl;
}

DownloadThread::~DownloadThread()
{
	delete m_pFtp;
}

void DownloadThread::run()
{
	m_pFtp->downLoad(m_strFtpPath, m_strLocalPath);
}

void DownloadThread::downLoad( const std::string& ftpPath, const std::string& localPath )
{
	m_strFtpPath = ftpPath;
	m_strLocalPath = localPath;
}
