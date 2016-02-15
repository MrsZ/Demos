#ifndef FTPDOWNLOAD_H
#define FTPDOWNLOAD_H

#include <QFileSystemModel>
#include "ui_FtpDownload.h"
#include "FtpCurl.h"
#include "commonDef.h"

class FtpDownload : public QWidget
{
	Q_OBJECT

public:
	FtpDownload(QWidget *parent = 0);
	~FtpDownload();

private slots:
	void slotDownload(QTreeWidgetItem* item);
	void slotUpload();
	void slotUpdata();
	void slotConnect();
	void slotCurrent(const QModelIndex& index);
	void slotProcessFtpInfo();
	void slotCustomContextMenuRequested(const QPoint& pos);
	void slotDeleteFile();
	void slotRenameFile();
	void slotRenameFile(QTreeWidgetItem* item, int column);

private:
	void initFileList(const QString& ftpPath, QTreeWidgetItem* item);
	QIcon fileExtensionIcon(const QString& name);

private:
	Ui::FtpDownload ui;
	FtpCurl m_ftp;
	QFileSystemModel* m_pFileModel;
	QString m_strDownloadDir;
	QString m_strRemoteDir;
	std::vector<DownInfo*> m_vecInfo;
	QString m_strOldName;
};

#endif // FTPDOWNLOAD_H
