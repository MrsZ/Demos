#include "HttpDownload.h"

HttpDownload::HttpDownload(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_pHttp = new HttpCurl;
	connect(ui.pushButtonDown, SIGNAL(clicked()), this, SLOT(slotDownload()));
}

HttpDownload::~HttpDownload()
{

}

void HttpDownload::slotDownload()
{
	m_pHttp->get(ui.lineEditDir->text().toLocal8Bit().data(),
		ui.lineEditUrl->text().toLocal8Bit().data());
}
