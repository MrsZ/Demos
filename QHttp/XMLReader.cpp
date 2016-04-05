#include "XMLReader.h"

XMLReader::XMLReader(const QString& strContent)
: m_strContent(strContent)
{
	m_pDocument = new QDomDocument;
	m_pDocument->setContent(strContent);
}

XMLReader::~XMLReader()
{

}

QString XMLReader::getValue(const QString& key, const QString& type)
{
	QString strResult = "";
	// ��ȡ���ͽڵ㼯��
	QDomNodeList nodelist = m_pDocument->elementsByTagName(type);
	for (int i = 0; i < nodelist.count(); ++i)
	{
		QDomNode node = nodelist.at(i);
		// ��ȡ�ӽڵ㼯��
		QDomNodeList itemlist = node.childNodes();
		int count = itemlist.count();
		for (int j = 0; j < itemlist.count(); ++j)
		{
			QDomNode mynode = itemlist.at(j);
			if (mynode.nodeName() == key)
			{
				// ��������Ҫ�ļ�ֵ
				strResult = mynode.toElement().attribute(key);
				break;
			}
		}
	}

	return strResult;
}
