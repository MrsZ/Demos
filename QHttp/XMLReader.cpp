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
	// 读取类型节点集合
	QDomNodeList nodelist = m_pDocument->elementsByTagName(type);
	for (int i = 0; i < nodelist.count(); ++i)
	{
		QDomNode node = nodelist.at(i);
		// 获取子节点集合
		QDomNodeList itemlist = node.childNodes();
		int count = itemlist.count();
		for (int j = 0; j < itemlist.count(); ++j)
		{
			QDomNode mynode = itemlist.at(j);
			if (mynode.nodeName() == key)
			{
				// 查找所需要的键值
				strResult = mynode.toElement().attribute(key);
				break;
			}
		}
	}

	return strResult;
}
