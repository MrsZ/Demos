////
// File: HttpCurl.h
// Author:lyk
// Date: 2016/01/20
// Desc: Http服务下载功能
//
#ifndef HTTPCURL_H
#define HTTPCURL_H
#include <iostream>

class HttpCurl
{
public:
	HttpCurl();
	~HttpCurl();

	std::string getLastError();

	// fileName:文件存储路径，url：下载URL
	bool get(const std::string& fileName, const std::string& url);

	// fileName:文件存储路径，url：下载URL
	bool post(const std::string& fileName, const std::string& url);

private:
	std::string m_strLastError;
};

#endif // HTTPCURL_H
