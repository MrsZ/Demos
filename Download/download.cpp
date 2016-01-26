#include "download.h"

Download::Download(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	init();
}

Download::~Download()
{

}

void Download::init()
{
	m_pFtp = new FtpDownload(this);
	m_pHttp = new HttpDownload(this);

	ui.tabWidget->addTab(m_pFtp, "Ftp");
	ui.tabWidget->addTab(m_pHttp, "Http");
}
