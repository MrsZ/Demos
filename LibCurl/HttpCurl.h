//
// File: HttpCurl.h
// Author:lyk
// Date: 2016/04/01
// Desc:
//
#ifndef HTTPCURL_H
#define HTTPCURL_H

#include <iostream>
#include <boost/format.hpp>

class HttpCurl
{
public:
	HttpCurl();
	~HttpCurl();

	std::string post(const std::string& loginName, const std::string& loginPasswd);

private:
	static size_t wirteData(void* ptr, size_t size, size_t nmemb, void* data);

private:
	static std::string m_strContent;       // ������Ϣ
	boost::format m_fmtLogin;              // ��¼���ݸ�ʽ
	std::string m_strLastErrot;            // ������Ϣ
};

#endif // HTTPCURL_H
