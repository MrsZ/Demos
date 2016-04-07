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

void HttpOperator::post(QUrl url, const std::string& strSend)
{
	QNetworkRequest request;
	request.setUrl(url);
	request.setRawHeader("POST", "/framework/api/SimulateInterface.asmx HTTP/1.1");
	request.setRawHeader("Host", "119.29.5.61");
	request.setRawHeader("Content-Type", "application/soap+xml; charset=utf-8");
	request.setRawHeader("Content-Length", QString("%1").arg(strSend.length()).toUtf8());
	m_pNetwork->post(request, strSend.c_str());
}

void HttpOperator::slotFinished(QNetworkReply* reply)
{
	QVariant statusCodeV =
		reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	QVariant redirectionTargetUrl =
		reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
	m_error = reply->error();
	if (m_error == QNetworkReply::NoError)
	{
		m_strRecv = QString::fromUtf8(reply->readAll());
	}

	emit signalFinished();

	reply->deleteLater();
}
