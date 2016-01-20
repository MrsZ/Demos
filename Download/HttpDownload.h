#ifndef HTTPDOWNLOAD_H
#define HTTPDOWNLOAD_H

#include <QWidget>
#include "ui_HttpDownload.h"
#include "HttpCurl.h"

class HttpDownload : public QWidget
{
	Q_OBJECT

public:
	HttpDownload(QWidget *parent = 0);
	~HttpDownload();

private slots:
	void slotDownload();

private:
	Ui::HttpDownload ui;
	HttpCurl* m_pHttp;
};

#endif // HTTPDOWNLOAD_H
