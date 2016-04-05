#include "qhttp1.h"
#include "XMLReader.h"

QHttp1::QHttp1(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	m_pHttp = new HttpOperator;
	m_pHttp->login("demo", "demo");
	connect(m_pHttp, SIGNAL(signalFinished()), this, SLOT(slotLoginResule()));
}

QHttp1::~QHttp1()
{

}

void QHttp1::slotLoginResule()
{
	XMLReader reader(m_pHttp->getRecv());
	QString strName = reader.getValue("loginname", "user");
	QString strID = reader.getValue("useruid", "user");
}
