////
// File: HttpCurl.h
// Author:lyk
// Date: 2016/01/20
// Desc: Http�������ع���
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

	// fileName:�ļ��洢·����url������URL
	bool get(const std::string& fileName, const std::string& url);

	// fileName:�ļ��洢·����url������URL
	bool post(const std::string& fileName, const std::string& url);

private:
	std::string m_strLastError;
};

#endif // HTTPCURL_H
