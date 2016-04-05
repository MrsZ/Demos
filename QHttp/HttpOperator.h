//
// File: HttpOperator.h
// Author:lyk
// Date: 2016/04/01
// Desc: qtµÄhttp²Ù×÷
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

	void login(const QString& name, const QString& passwd);
	QString getRecv() { return m_strRecv; }
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
