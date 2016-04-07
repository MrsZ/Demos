#include "qhttp1.h"
#include "XMLReader.h"

QHttp1::QHttp1(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QUrl url("http://119.29.5.61:8003/framework/api/SimulateInterface.asmx");
	m_pHttp = new HttpOperator;
	QString content = QString("<?xml version=\"1.0\" encoding=\"utf-8\"?>"
		"<soap12:Envelope xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:soap12=\"http://www.w3.org/2003/05/soap-envelope\">"
		"<soap12:Body>"
		"<Login xmlns=\"http://tempuri.org/\">"
		"<loginname>%1</loginname>"
		"<password>%2</password>"
		"</Login>"
		"</soap12:Body>"
		"</soap12:Envelope>"
		).arg("demo").arg("demo");
	m_pHttp->post(url, content.toLocal8Bit().data());
	connect(m_pHttp, SIGNAL(signalFinished()), this, SLOT(slotLoginResule()));
}

QHttp1::~QHttp1()
{

}

void QHttp1::slotLoginResule()
{
	/*
		QString str = m_pHttp->getRecv();
		str.replace("&lt;", "<");
		str.replace("&gt;", ">");
		str.replace("<?xml version=\"1.0\" encoding=\"utf-8\" ?>", "");
		str.replace("<?xml version=\"1.0\" encoding=\"utf-8\"?>", "");
		str.replace("< >", "");
		str.replace("</ >", "");
	*/
	XMLReader reader(m_pHttp->getRecv());
	QString strName = reader.getValue("loginname", "user");
	QString strID = reader.getValue("useruid", "user");

	QUrl url("http://119.29.5.61:8003/framework/api/SimulateInterface.asmx");
	QString content = QString("<?xml version=\"1.0\" encoding=\"utf-8\"?>"
		"<soap12:Envelope xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:soap12=\"http://www.w3.org/2003/05/soap-envelope\">"
		"<soap12:Body>"
		"<GetSimulateGrade xmlns=\"http://tempuri.org/\">"
		"<gradelist>"
		"<grade>"
		"<useruid>%1</useruid>"
		"<type>%2</type>"
		"<simulatename>%3</simulatename>"
		"<simulateuid>%4</simulateuid>"
		"<score>%5</score>"
		"</grade>"
		"</gradelist>"
		"</GetSimulateGrade>"
		"</soap12:Body>"
		"</soap12:Envelope>"
		).arg("8f327a18-2c30-4070-be6e-9135ce5e2629").arg("3").arg("隐患考核").arg("").arg(80);
	m_pHttp->post(url, content.toLocal8Bit().data());
}
