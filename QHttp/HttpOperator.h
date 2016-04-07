//
// File: HttpOperator.h
// Author:lyk
// Date: 2016/04/01
// Desc: qt的http操作
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

	// 实现post方法模拟webserver
	void post(QUrl url, const std::string& strSend);

	// 获取post方法成功后的返回信息
	QString getRecv() { return m_strRecv; }

	// 获取服务器返回的错误信息
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
