#ifndef DOWNLOADTHREAD_H
#define DOWNLOADTHREAD_H

#include <QThread>
#include "FtpCurl.h"

class DownloadThread : public QThread
{
	Q_OBJECT

public:
	DownloadThread(QObject *parent = 0);
	~DownloadThread();

	typedef enum{
		FTP_DOWNLOAD,
		FTP_UPLOAD,
		FTP_DELETE,
		FTP_RENAME,
		FTP_NONE
	}FtpType;

	void downLoad(const std::string& ftpPath,
		const std::string& localPath,
		FtpType type = FtpType::FTP_DOWNLOAD);

	virtual void run();

public:
	FtpCurl* m_pFtp;
	FtpType m_type;
	int m_iResult;
	std::string m_strFtpPath;
	std::string m_strLocalPath;
};

#endif // DOWNLOADTHREAD_H
