//
// File: HttpOperator.h
// Author:lyk
// Date: 2016/04/01
// Desc: qt��http����
//
#ifndef HTTPOPERATOR_H
#define HTTPOPERATOR_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class HttpOperator : public QObject
{
	Q_OBJECT

public:
	HttpOperator(QObject *parent = 0);
	~HttpOperator();

	// ʵ��post����ģ��webserver
	void post(QUrl url, const std::string& strSend);

	// ��ȡpost�����ɹ���ķ�����Ϣ
	QString getRecv() { return m_strRecv; }

	// ��ȡ���������صĴ�����Ϣ
	QNetworkReply::NetworkError getLastError(){ return m_error; }

private slots:
	void slotFinished(QNetworkReply* reply);

signals:
	void signalFinished();

private:
	QNetworkAccessManager* m_pNetwork;
	QString m_strRecv;
	QNetworkReply::NetworkError m_error;
};

#endif // HTTPOPERATOR_H
