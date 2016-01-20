#include "FtpCurl.h"
#include <curl/curl.h>
#include <QString>

FtpCurl::FtpCurl(void)
{
	m_lTimeOut = 1;
	m_lTrise = 3;
	m_pDownInfo = NULL;

	curl_global_init(CURL_GLOBAL_ALL);
}

FtpCurl::~FtpCurl(void)
{
	curl_global_cleanup();
}

void FtpCurl::setConnect(const std::string& ftpName,
						 const std::string& ftpPassword,
						 const std::string& ftpIp,
						 long timeout, long trise )
{
	m_strFtpName = ftpName;
	m_strFtpPassword = ftpPassword;
	m_strFtpIPAddress = ftpIp;
	m_lTimeOut = timeout;
	m_lTrise = trise;
}

size_t FtpCurl::wirteFile( void *ptr, size_t size, size_t nmemb, void* stream )
{
	return fwrite(ptr, size, nmemb, (FILE*)stream);
}

size_t FtpCurl::contentlegth( void* ptr, size_t size, size_t nmemb, void* stream )
{
	long len = 0;
	int ret = sscanf((char*)ptr, "Content-Length: %ld/n", &len);

	if (ret)
	{
		*((long *) stream) = len;
	}

	return size * nmemb;
}

std::string FtpCurl::getLastError()
{
	return m_strLastErrot;
}

size_t FtpCurl::discard( void* ptr, size_t size, size_t nmemb, void* stream )
{
	return size * nmemb;
}

size_t FtpCurl::readFile( void* ptr, size_t size, size_t nmemb, void* stream )
{
	return fread(ptr, size, nmemb, (FILE*)stream) * size;
}

void FtpCurl::setProcess(DownInfo* info)
{
	m_pDownInfo = info;
}

int FtpCurl::progress( DownInfo *ptr, double t, double d, double ultotal, double ulnow )
{
	ptr->count = d;
	ptr->size = t;

	return 0;
}

int FtpCurl::downLoad( const std::string& ftpPath, const std::string& localPath )
{
	int ret = 0;
	long fileSize = 0;
	FILE* file = fopen(localPath.c_str(), "wb+");
	if (!file)
	{
		return -1;
	}

	// 获取文件在服务器的位置信息，格式如：ftp://admin:123456@192.168.3.91/1111.doc
	std::string strUser = m_strFtpName;
	strUser.append(":");
	strUser.append(m_strFtpPassword);

	std::string strIP = m_strFtpIPAddress;
	strIP.append(ftpPath);

	CURL* pCurlHandleDown = curl_easy_init();
	curl_easy_setopt(pCurlHandleDown, CURLOPT_URL, strIP.c_str());
	curl_easy_setopt(pCurlHandleDown, CURLOPT_USERPWD, strUser.c_str());

	// 设置超时
	curl_easy_setopt(pCurlHandleDown, CURLOPT_CONNECTTIMEOUT, m_lTimeOut);

	// 设置头处理函数
	curl_easy_setopt(pCurlHandleDown, CURLOPT_HEADERFUNCTION, FtpCurl::contentlegth);

	// 获取长度值
	curl_easy_setopt(pCurlHandleDown, CURLOPT_HEADERDATA, &fileSize);

	// 写文件
	curl_easy_setopt(pCurlHandleDown, CURLOPT_WRITEFUNCTION, FtpCurl::wirteFile); 
	curl_easy_setopt(pCurlHandleDown, CURLOPT_WRITEDATA, file);
	curl_easy_setopt(pCurlHandleDown, CURLOPT_NOPROGRESS, 1L);
	curl_easy_setopt(pCurlHandleDown, CURLOPT_VERBOSE, 1L);
	if (m_pDownInfo)
	{
		curl_easy_setopt(pCurlHandleDown, CURLOPT_PROGRESSFUNCTION, FtpCurl::progress);
		curl_easy_setopt(pCurlHandleDown, CURLOPT_PROGRESSDATA, m_pDownInfo);
	}
	CURLcode r = curl_easy_perform(pCurlHandleDown);

	fclose(file);
	if (r != CURLE_OK)
	{
		ret = -1;
		m_strLastErrot = curl_easy_strerror(r);
	}

	curl_easy_cleanup(pCurlHandleDown);
	return ret;
}

int FtpCurl::upLoad( const std::string& ftpPath, const std::string& localPath )
{
	int ret = 0;
	long fileSize = 0;
	FILE* file = fopen(localPath.c_str(), "rb+");
	if (!file)
	{
		return -1;
	}

	// 获取文件在服务器的位置信息，格式如：ftp://admin:123456@192.168.3.91/1111.doc
	std::string strUser = m_strFtpName;
	strUser.append(":");
	strUser.append(m_strFtpPassword);

	std::string strIP = m_strFtpIPAddress;
	strIP.append(ftpPath);

	CURL* pCurlHandleUp = curl_easy_init();
	curl_easy_setopt(pCurlHandleUp, CURLOPT_URL, strIP.c_str());
	curl_easy_setopt(pCurlHandleUp, CURLOPT_USERPWD, strUser.c_str());
	curl_easy_setopt(pCurlHandleUp, CURLOPT_UPLOAD, 1L);

	// 设置超时
	curl_easy_setopt(pCurlHandleUp, CURLOPT_FTP_RESPONSE_TIMEOUT, m_lTimeOut);

	curl_easy_setopt(pCurlHandleUp, CURLOPT_HEADERFUNCTION, FtpCurl::contentlegth);
	curl_easy_setopt(pCurlHandleUp, CURLOPT_HEADERDATA, &fileSize);
	curl_easy_setopt(pCurlHandleUp, CURLOPT_WRITEFUNCTION, FtpCurl::discard);

	// 读文件
	curl_easy_setopt(pCurlHandleUp, CURLOPT_READFUNCTION, FtpCurl::readFile);
	curl_easy_setopt(pCurlHandleUp, CURLOPT_READDATA, file);
	curl_easy_setopt(pCurlHandleUp, CURLOPT_FTPPORT, "-");
	curl_easy_setopt(pCurlHandleUp, CURLOPT_FTP_CREATE_MISSING_DIRS, 1L);
	curl_easy_setopt(pCurlHandleUp, CURLOPT_VERBOSE, 1L);
	
	CURLcode r = CURLE_GOT_NOTHING;
	for (int i = 0; r != CURLE_OK && i < m_lTrise; ++i)
	{
		if (i)
		{
			curl_easy_setopt(pCurlHandleUp, CURLOPT_NOBODY, 1L);
			curl_easy_setopt(pCurlHandleUp, CURLOPT_HEADER, 1L);
			r = curl_easy_perform(pCurlHandleUp);
			if (r != CURLE_OK)
			{
				continue;
			}
			curl_easy_setopt(pCurlHandleUp, CURLOPT_NOBODY, 0L);
			curl_easy_setopt(pCurlHandleUp, CURLOPT_HEADER, 0L);
			fseek(file, fileSize, SEEK_SET);
			curl_easy_setopt(pCurlHandleUp, CURLOPT_APPEND, 1L);
		}
		else
		{
			curl_easy_setopt(pCurlHandleUp, CURLOPT_APPEND, 0L);
		}

		r = curl_easy_perform(pCurlHandleUp);
	}

	fclose(file);
	if (r != CURLE_OK)
	{
		ret = -1;
		m_strLastErrot = curl_easy_strerror(r);
	}

	curl_easy_cleanup(pCurlHandleUp);
	return ret;
}
