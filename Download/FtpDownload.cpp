#include "FtpDownload.h"
#include <QFile>
#include <QUrl>
#include <QTextCodec>
#include <QFileDialog>
#include <QTextStream>
#include <QTimer>
#include "FileUtils.h"
#include "DownloadThread.h"

FtpDownload::FtpDownload(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	m_vecInfo.clear();
	m_strDownloadDir = FileUtils::ins()->getDataPathQString();
	m_pFileModel = new QFileSystemModel;
	m_pFileModel->setRootPath("");
	ui.treeViewDownload->setAnimated(false);
	ui.treeViewDownload->setIndentation(20);
	ui.treeViewDownload->setSortingEnabled(true);
	ui.treeViewDownload->setModel(m_pFileModel);
	ui.lineEditPassw->setEchoMode(QLineEdit::Password);
	connect(ui.pushButtonOpen, SIGNAL(clicked()), this, SLOT(slotConnect()));
	connect(ui.pushButtonUp, SIGNAL(clicked()), this, SLOT(slotUpload()));
	connect(ui.pushButtonUpdate, SIGNAL(clicked()), this, SLOT(slotUpdata()));
	connect(ui.treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), 
		this, SLOT(slotDownload(QTreeWidgetItem*)));
	connect(ui.treeViewDownload, SIGNAL(doubleClicked(const QModelIndex&)),
		this,SLOT(slotCurrent(const QModelIndex&)));

// 	QTimer *timer = new QTimer(this);
// 	connect(timer, SIGNAL(timeout()), this, SLOT(slotProcessFtpInfo()));
// 	timer->start();
}

FtpDownload::~FtpDownload()
{
	
}

void FtpDownload::slotConnect()
{
	QString strName = ui.lineEditUser->text();
	QString strPasswd = ui.lineEditPassw->text();
	QString strIp= ui.lineEditIp->text();

	m_ftp.setConnect(strName.toStdString(),
		strPasswd.toStdString(),
		strIp.toStdString());

	ui.treeWidget->clear();
	ui.treeWidget->setColumnCount(5);
	QTreeWidgetItem* pItem = new QTreeWidgetItem;
	pItem->setText(0, "/");
	pItem->setData(0, Qt::UserRole, "/");
	pItem->setExpanded(true);
	ui.treeWidget->addTopLevelItem(pItem);
	initFileList("/", pItem);
}

void FtpDownload::slotDownload(QTreeWidgetItem* item)
{
	if (item->childCount() > 0)
	{
		m_strRemoteDir = item->data(0, Qt::UserRole).toString();
		m_strRemoteDir.append("/");
		return;
	}
	DownloadThread* thr = new DownloadThread;
	thr->m_pFtp->setConnect(ui.lineEditUser->text().toStdString(),
		ui.lineEditPassw->text().toStdString(),
		ui.lineEditIp->text().toStdString());
	QString strName = item->data(0, Qt::UserRole).toString();
	int nPos = strName.lastIndexOf("/");
	strName = strName.right(strName.length() - nPos);
	QString strLoacal = m_strDownloadDir;
	strLoacal.append(strName);
	DownInfo* pInfo = new DownInfo;
	pInfo->down = true;
	pInfo->name = strName.toLocal8Bit().data();
	thr->m_pFtp->setProcess(pInfo);
	thr->downLoad(item->data(0, Qt::UserRole).toString().toLocal8Bit().data(),
		strLoacal.toLocal8Bit().data());

	QString strContent = QString("正在下载 ");
	strContent.append(strName).append("              到 ").append(strLoacal);
	ui.textEdit->append(strContent);
	m_vecInfo.push_back(pInfo);
	connect(thr, SIGNAL(finished()), thr, SLOT(deleteLater()));
	thr->start();
}

void FtpDownload::slotUpload()
{
	QStringList files = QFileDialog::getOpenFileNames(
		this,
		tr("选择文档"),
		"",
		"Document (*.doc *.docx *.xls *.xlsx *.ppt *.pptx *.pdf)");
	QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
	foreach (QString file, files)
	{
		QFileInfo info(file);
		m_ftp.upLoad(info.fileName().toLocal8Bit().data(), file.toLocal8Bit().data());
	}
	QApplication::restoreOverrideCursor();
}

void FtpDownload::slotUpdata()
{
	slotConnect();
}

void FtpDownload::initFileList(const QString& ftpPath, QTreeWidgetItem* item)
{
	QString strPath = FileUtils::ins()->getDataPathQString("list");
	int ret = m_ftp.downLoad(ftpPath.toLocal8Bit().data(),
		strPath.toLocal8Bit().data());
	if (ret != 0)
	{
		QString strErr = QString::fromStdString(m_ftp.getLastError());
	}

	QFile file(strPath);
	QString strContent;
	if (file.open(QIODevice::ReadOnly))
	{
		QTextStream stream(&file);  
		stream.setCodec(QTextCodec::codecForName("GBK"));
		strContent = stream.readAll();
	}

	QStringList fileList = strContent.split("\r\n");
	int i = 0;
	QTreeWidgetItem* pItem = NULL;
	foreach (QString str, fileList)
	{
		str = str.simplified();
		QStringList list = str.split(" ");
		if(list.size() < 9)
		{
			continue;
		}

		int row = 0;
		pItem = new QTreeWidgetItem;
		QString strName = list.at(8);
		for (int j = 9; j < list.size(); ++j)
		{
			strName.append(" ").append(list.at(j));
		}
		pItem->setText(0, strName);         // 名称
		pItem->setData(0, Qt::UserRole, ftpPath + strName);

		float size = list.at(4).toFloat();

		if (size == 0)
		{
			pItem->setIcon(0, QIcon(":/Download/Resources/fileblue.png"));
			initFileList(ftpPath + strName + "/", pItem);
		}
		else
		{
			QString strSize;
			if (size < 1024)
			{
				strSize = QString("b");
			}
			else if (size >= 1024 && size < 1024 * 1024)
			{
				size = size / 1024.0;
				strSize = QString("Kb");
			}
			else if (size >= 1024 * 1024 && size < 1024 * 1024 * 1024)
			{
				size = size / 1024.0 / 1024.0;
				strSize = QString("Mb");
			}
			else if(size >= 1024 * 1024 * 1024)
			{
				size = size / 1024.0 / 1024.0 / 1024.0;
				strSize = QString("Gb");
			}
			pItem->setIcon(0, QIcon(":/Download/Resources/download.png"));
			pItem->setText(1, QString::number(size, 'g', 4).append(strSize));        // 大小
		}
		pItem->setText(2, list.at(5) + " " + list.at(6) + " " + list.at(7));        // 日期

		item->addChild(pItem);
		++i;
	}
}

void FtpDownload::slotCurrent( const QModelIndex& index )
{
	if (m_pFileModel->isDir(index))
	{
		m_strDownloadDir = m_pFileModel->filePath(index);
	}
	else
	{
		QString strup = m_pFileModel->filePath(index);
		DownloadThread* thr = new DownloadThread;
		thr->m_pFtp->setConnect(ui.lineEditUser->text().toStdString(),
			ui.lineEditPassw->text().toStdString(),
			ui.lineEditIp->text().toStdString());

		QString strRemote = m_strRemoteDir;
		strRemote.append(m_pFileModel->fileName(index));
		thr->downLoad(strRemote.toLocal8Bit().data(),
			strup.toLocal8Bit().data(), false);

		QString strContent = QString(tr("正在上传 "));
		strContent.append(strup).append(tr("              到 ")).append(m_strRemoteDir);
		ui.textEdit->append(strContent);
		connect(thr, SIGNAL(finished()), thr, SLOT(deleteLater()));
		thr->start();
	}
}

void FtpDownload::slotProcessFtpInfo()
{
	int i = 0;
	foreach(DownInfo* iter, m_vecInfo)
	{
		if (iter->size == iter->count)
		{
			m_vecInfo.erase(m_vecInfo.begin() + i);
		}
		QString strContent;
		if (iter->down)
		{
			strContent = QString(tr("正在下载 "));
		}
		else
		{
			strContent = QString(tr("正在上传 "));
		}
		strContent.append(QString::fromStdString(iter->name));
		strContent.append(" ");
		strContent.append(QString::number(iter->size / iter->count *100));
		strContent.append("%");

		ui.textEdit->append(strContent);
		++i;
	}
}
