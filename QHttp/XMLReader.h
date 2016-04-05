//
// File: XMLReader.h
// Author:lyk
// Date: 2016/04/05
// Desc: ∂¡»°xmlµƒ¿‡
//
#ifndef XMLREADER_H
#define XMLREADER_H

#include <QDomDocument>
#include <QString>

class XMLReader
{
public:
	XMLReader(const QString& strContent);
	~XMLReader();

	QString getValue(const QString& key, const QString& type = "user");

private:
	QString m_strContent;
	QDomDocument* m_pDocument;
};

#endif // XMLREADER_H
