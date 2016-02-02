#include "DownloadThread.h"

DownloadThread::DownloadThread(QObject *parent)
: QThread(parent)
{
	m_type = FtpType::FTP_NONE;
	m_iResult = -1;
}

DownloadThread::~DownloadThread()
{
	
}

void DownloadThread::run()
{
	switch (m_type)
	{
	case FTP_DOWNLOAD:
		m_iResult = m_pFtp->downLoad(m_strFtpPath, m_strLocalPath);
		break;
	case FTP_UPLOAD:
		m_iResult = m_pFtp->upLoad(m_strFtpPath, m_strLocalPath);
		break;
	case FTP_DELETE:
		m_iResult = m_pFtp->deleteFile(m_strFtpPath);
		break;
	default:
		m_iResult = 0;
		break;
	}
}

void DownloadThread::downLoad(const std::string& ftpPath,
	const std::string& localPath,
	FtpType type)
{
	m_type = type;
	m_strFtpPath = ftpPath;
	m_strLocalPath = localPath;
}
