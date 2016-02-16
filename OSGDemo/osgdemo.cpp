#include "osgdemo.h"
#include <QFileDialog>
#include <osgDB/ReadFile>

OSGDemo::OSGDemo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	m_p3DWidget = new Widget3D(this);
	this->setCentralWidget(m_p3DWidget);

	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(slotAddModels()));
	connect(ui.listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
		this, SLOT(slotDoubleClickedList(QListWidgetItem*)));
}

OSGDemo::~OSGDemo()
{

}

void OSGDemo::slotAddModels()
{
	QStringList listModels = QFileDialog::getOpenFileNames(
		this,
		"Select one or more files to open",
		"D:/SSIT/project/3dEngine/STSDK/Tool/QtDockWidget/Data",
		"Images (*.osg *.ive *.osgd)");

	m_p3DWidget->getRoot()->removeChildren(0, m_p3DWidget->getRoot()->getNumChildren());
	foreach(QString model, listModels)
	{
		m_p3DWidget->getRoot()->addChild(osgDB::readNodeFile(model.toLocal8Bit().data()));
	}
}

void OSGDemo::initDockList()
{
	QStringList list = QStringList() << "1103CSL128"<< "1103CSL001"
		<< "1103CSL009"<< "1103CSL008"<< "1103CSL027"<< "1103CSL028"
		<< "1103CSL029"<< "1103CSL002"<< "1103CSL004"<< "1103CSL125"
		<< "1103CSL003"<< "1103CSL024"<< "1103CSL025";

	ui.listWidget->addItems(list);
}

void OSGDemo::slotDoubleClickedList( QListWidgetItem* item )
{
	
}
