#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QtGui/QMainWindow>
#include "ui_download.h"
#include "FtpDownload.h"
#include "HttpDownload.h"

class Download : public QMainWindow
{
	Q_OBJECT

public:
	Download(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Download();

private:
	void init();

private:
	Ui::DownloadClass ui;
	FtpDownload* m_pFtp;
	HttpDownload* m_pHttp;
};

#endif // DOWNLOAD_H
