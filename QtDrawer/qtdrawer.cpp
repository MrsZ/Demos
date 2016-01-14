#include "qtdrawer.h"
#include <QDir>
#include <QFileInfo>
#include <QIcon>
#include <QColorDialog>
#include <QMessageBox>
#include "FileUtils.h"

QtDrawer::QtDrawer(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	m_pDraw = new DrawAreaWidget(ui.widget);

	ui.pushButtonSave->setDisabled(false);
	m_strCurrentFile = "";
	QHBoxLayout * horizontalLayout = new QHBoxLayout(ui.widget);
	horizontalLayout->addWidget(m_pDraw);

	initList();

	connect(ui.listWidgetUnSign, SIGNAL(itemClicked(QListWidgetItem*)),
		this, SLOT(slotDoubleUnSigned(QListWidgetItem*)));
	connect(ui.listWidgetSigned, SIGNAL(itemClicked(QListWidgetItem*)),
		this, SLOT(slotDoubleSigned(QListWidgetItem*)));

	connect(ui.pushButtonSave, SIGNAL(clicked()), this, SLOT(slotSave()));
	connect(ui.pushButtonExit, SIGNAL(clicked()), this, SLOT(slotExit()));

	connect(ui.pushButtonColor, SIGNAL(clicked()), this, SLOT(slotColorSelect()));
	connect(ui.pushButtonReDraw, SIGNAL(clicked()), this, SLOT(slotReDraw()));
}

QtDrawer::~QtDrawer()
{

}

void QtDrawer::initList()
{
	// 遍历左侧
	ui.listWidgetUnSign->clear();
	QString strDir = FileUtils::ins()->getDataPathQString(QString::fromLocal8Bit("未签到"));
	//QMessageBox::information(this, "text", strDir);
	QDir dir(strDir);

	QFileInfoList fileList = dir.entryInfoList(QStringList() << "*.png"
		<< "*.jpg" << "*.jpeg");
	QListWidgetItem* pItem = NULL;
	foreach(QFileInfo file, fileList)
	{
		pItem = new QListWidgetItem;
		pItem->setIcon(QIcon(file.absoluteFilePath()));
		QString str = file.baseName();
		QString str1 = file.absoluteFilePath();
		pItem->setText(file.baseName());
		pItem->setData(Qt::UserRole, file.absoluteFilePath());
		ui.listWidgetUnSign->addItem(pItem);
	}

	// 遍历右侧
	ui.listWidgetSigned->clear();
	ui.listWidgetSigned->setIconSize(QSize(32,32));
	dir.setPath(FileUtils::ins()->getDataPathQString(QString::fromLocal8Bit("已签到")));

	fileList = dir.entryInfoList(QStringList() << "*.png" << "*.jpg");
	foreach(QFileInfo file, fileList)
	{
		pItem = new QListWidgetItem;
		pItem->setIcon(QIcon(file.absoluteFilePath()));
		pItem->setText(file.baseName());
		pItem->setData(Qt::UserRole, file.absoluteFilePath());
		ui.listWidgetSigned->addItem(pItem);
	}
}

void QtDrawer::slotDoubleUnSigned( QListWidgetItem* item )
{
	if (item == NULL)
	{
		return;
	}

	m_strCurrentFile = item->data(Qt::UserRole).toString();
	m_pDraw->setPixmapPath(m_strCurrentFile, ui.widget->width(), ui.widget->height());
	ui.pushButtonSave->setDisabled(false);
}

void QtDrawer::slotDoubleSigned( QListWidgetItem* item )
{
	if (item == NULL)
	{
		return;
	}

	m_strCurrentFile = "";
	m_pDraw->setPixmapPath(item->data(Qt::UserRole).toString(),
		ui.widget->width(), ui.widget->height());
	ui.pushButtonSave->setDisabled(true);
}

void QtDrawer::slotSave()
{
	QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
	QPixmap pix = QPixmap::grabWindow(m_pDraw->winId());
	QFileInfo info(m_strCurrentFile);
	pix.save(FileUtils::ins()->getDataPathQString(
		QString::fromLocal8Bit("已签到/")).append(info.baseName()).append(".png"), "PNG");

	QFile::remove(m_strCurrentFile);
	m_strCurrentFile = "";
	initList();
	ui.pushButtonSave->setDisabled(true);
	QApplication::restoreOverrideCursor();
}

void QtDrawer::slotExit()
{
	exit(0);
}

void QtDrawer::slotColorSelect()
{
	QColor color = QColorDialog::getColor();
	color.setAlpha(200);
	m_pDraw->setPenColor(color);
	QString strColor = QString("background-color: rgba(%1,%2,%3,%4);")
.arg(color.red()).arg(color.green()).arg(color.blue()).arg(color.alpha());
	ui.pushButtonColor->setStyleSheet(strColor);
}

void QtDrawer::slotReDraw()
{
	m_pDraw->clearWidget();
}
