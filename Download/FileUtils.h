////
// File: fileutils.h
// Author:lyk
// Date: 2015/12/28
// Desc: 路径的统一获取方式
//
#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <QString>
#include <QApplication>

class FileUtils
{
public:
	static FileUtils* ins();
	static void del();

	QString getDataPathQString(const QString& name = "");
	std::string getDataPathString(const std::string& name /* = */ );

private:
	FileUtils();
	~FileUtils();

private:
	static FileUtils* m_pIns;
	QString m_strRoot;
};

#endif // FILEUTILS_H
