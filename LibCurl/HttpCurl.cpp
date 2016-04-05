#include "HttpCurl.h"
#include <curl/curl.h>

std::string HttpCurl::m_strContent = "";

HttpCurl::HttpCurl()
{
	m_strLastErrot = "";

	m_fmtLogin = boost::format("<?xml version=\"1.0\" encoding=\"utf-8\"?>"
		"<soap12:Envelope xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:soap12=\"http://www.w3.org/2003/05/soap-envelope\">"
		"<soap12:Body>"
		"<Login xmlns=\"http://tempuri.org/\">"
		"<loginname>demo</loginname>"
		"<password>demo</password>"
		"</Login>"
		"</soap12:Body>"
		"</soap12:Envelope>"
		);

	curl_global_init(CURL_GLOBAL_ALL);
}

HttpCurl::~HttpCurl()
{
	curl_global_cleanup();
}

size_t HttpCurl::wirteData(void* ptr, size_t size, size_t nmemb, void* data)
{
	char httpsBuffer[2048];
	memset(httpsBuffer, 0, sizeof(httpsBuffer));
	memcpy(httpsBuffer, ptr, nmemb);

	m_strContent += httpsBuffer;
	
	return nmemb * size;
}

std::string HttpCurl::post(const std::string& loginName, const std::string& loginPasswd)
{
	m_strContent = "";

	//m_fmtLogin % loginName % loginPasswd;

	struct curl_slist* header = 0;
	boost::format fmt("Content-Length:381");
	
	header = curl_slist_append(header, "POST /framework/api/SimulateInterface.asmx");
	header = curl_slist_append(header, "Host:119.29.5.61");
	header = curl_slist_append(header, "Content-Type:application/soap+xml; charset=utf-8");
	header = curl_slist_append(header, "Content-Length:349");

	CURL* pCurlHandlPost = curl_easy_init();
	curl_easy_setopt(pCurlHandlPost, CURLOPT_URL, "http://119.29.5.61:8003");
	curl_easy_setopt(pCurlHandlPost, CURLOPT_HEADER, header);
	curl_easy_setopt(pCurlHandlPost, CURLOPT_POSTFIELDS, m_fmtLogin.str().c_str());
  

	// Ð´ÎÄ¼þ
	curl_easy_setopt(pCurlHandlPost, CURLOPT_WRITEFUNCTION, HttpCurl::wirteData);
	curl_easy_setopt(pCurlHandlPost, CURLOPT_NOPROGRESS, 1L);
	curl_easy_setopt(pCurlHandlPost, CURLOPT_VERBOSE, 1L);
	CURLcode r = curl_easy_perform(pCurlHandlPost);

	if (r != CURLE_OK)
	{
		m_strLastErrot = curl_easy_strerror(r);
	}

	curl_easy_cleanup(pCurlHandlPost);
	return m_strContent;
}
