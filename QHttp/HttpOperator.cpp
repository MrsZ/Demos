#include "HttpOperator.h"

HttpOperator::HttpOperator(QObject *parent)
	: QObject(parent)
{
	m_pNetwork = new QNetworkAccessManager;
	connect(m_pNetwork, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotFinished(QNetworkReply*)));
}

HttpOperator::~HttpOperator()
{

}

void HttpOperator::login(const QString& name, const QString& passwd)
{
	QUrl url("http://119.29.5.61:8003/framework/api/SimulateInterface.asmx");
	QString content = QString("<?xml version=\"1.0\" encoding=\"utf-8\"?>"
		"<soap12:Envelope xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:soap12=\"http://www.w3.org/2003/05/soap-envelope\">"
		"<soap12:Body>"
		"<Login xmlns=\"http://tempuri.org/\">"
		"<loginname>%1</loginname>"
		"<password>%2</password>"
		"</Login>"
		"</soap12:Body>"
		"</soap12:Envelope>"
		).arg(name).arg(passwd);
	QNetworkRequest request;
	request.setUrl(url);
	request.setRawHeader("POST", url.path().toUtf8());
	request.setRawHeader("Host", url.host().toUtf8());
	int i = content.length();
	request.setRawHeader("Content-Type", "application/soap+xml; charset=utf-8");
	request.setRawHeader("Content-Length", QString("%1").arg(content.length()).toUtf8());
	QNetworkReply* reply = m_pNetwork->post(request, content.toUtf8());
}

void HttpOperator::slotFinished(QNetworkReply* reply)
{
	QVariant statusCodeV =
		reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	QVariant redirectionTargetUrl =
		reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
	std::string str;
	m_error = reply->error();
	if (m_error == QNetworkReply::NoError)
	{
		QString string = QString::fromUtf8(reply->readAll());
		string.replace("&lt;", "<");
		string.replace("&gt;", ">");
		string.replace("<?xml version=\"1.0\" encoding=\"utf-8\" ?>", "");
		string.replace("<?xml version=\"1.0\" encoding=\"utf-8\"?>", "");
		string.replace("< >", "");
		string.replace("</ >", "");
		m_strRecv = string;
	}

	emit signalFinished();

	reply->deleteLater();
}
