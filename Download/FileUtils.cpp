#include "fileutils.h"

FileUtils* FileUtils::m_pIns = NULL;

FileUtils::FileUtils()
{
	m_strRoot = QApplication::applicationDirPath();
	m_strRoot.append("/../Data/");
}

FileUtils::~FileUtils()
{

}

FileUtils* FileUtils::ins()
{
	if (m_pIns == NULL)
	{
		m_pIns = new FileUtils;
	}

	return m_pIns;
}

void FileUtils::del()
{
	delete m_pIns;
}

QString FileUtils::getDataPathQString( const QString& name /*= ""*/ )
{
	return m_strRoot + name;
}

std::string FileUtils::getDataPathString( const std::string& name /* = */ )
{
	QString str = m_strRoot + QString::fromStdString(name);
	return str.toLocal8Bit().data();
}
