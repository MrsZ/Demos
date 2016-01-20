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

	void downLoad(const std::string& ftpPath,
		const std::string& localPath,
		bool isDown = true);

	virtual void run();

public:
	FtpCurl* m_pFtp;
	bool m_bDown;
	std::string m_strFtpPath;
	std::string m_strLocalPath;
};

#endif // DOWNLOADTHREAD_H
