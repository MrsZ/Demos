#include "HttpCurl.h"
#include <curl/curl.h>

HttpCurl::HttpCurl()
{
	curl_global_init(CURL_GLOBAL_ALL);
}

HttpCurl::~HttpCurl()
{
	curl_global_cleanup();
}

std::string HttpCurl::getLastError()
{
	return m_strLastError;
}

bool HttpCurl::get( const std::string& fileName, const std::string& url )
{
	FILE *fp;
	bool ret = false;
	if ((fp = fopen(fileName.c_str(), "wb+")) == NULL)
	{
		return false;
	}

	struct curl_slist *headers = NULL;
	headers = curl_slist_append(headers, "Accept: Agent-007");
	CURL* curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		curl_easy_setopt(curl, CURLOPT_HEADERDATA, fp);
		CURLcode res = curl_easy_perform(curl);
		if (res != CURLE_OK)
		{
			m_strLastError = curl_easy_strerror(res);
			curl_slist_free_all(headers);
		}
		fclose(fp);
		curl_easy_cleanup(curl);
		ret = true;
	}

	return ret;
}

bool HttpCurl::post( const std::string& fileName, const std::string& url )
{
	bool ret = false;

	return ret;
}
