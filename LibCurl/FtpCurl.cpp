#include <NetWork/FtpCurl.h>
#include <curl/curl.h>
#include <ConvTool/StringConv.h>

FtpCurl::FtpCurl(void)
{
	m_lTimeOut = 1;
	m_lTrise = 3;

	curl_global_init(CURL_GLOBAL_ALL);
// 	m_pCurlHandleDown = curl_easy_init();
// 	m_pCurlHandleUp = curl_easy_init();
}

FtpCurl::~FtpCurl(void)
{
// 	curl_easy_cleanup(m_pCurlHandleDown);
// 	curl_easy_cleanup(m_pCurlHandleUp);
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

int FtpCurl::listFiles(const std::string& ftpPath, std::string& strContent)
{
	int ret = 0;
	std::string remotePaht = "ftp://";
	remotePaht.append(m_strFtpName);
	remotePaht.append(":");
	remotePaht.append(m_strFtpPassword);
	remotePaht.append("@");
	remotePaht.append(m_strFtpIPAddress);
	remotePaht.append(ftpPath);
	
	FILE *ftpfile = fopen("../list", "wb+");
	FILE *respfile = fopen("../list-res", "wb+");

	CURL* listHandle = curl_easy_init();
	curl_easy_setopt(listHandle, CURLOPT_URL, remotePaht.c_str());
	curl_easy_setopt(listHandle, CURLOPT_WRITEDATA, ftpfile);
	curl_easy_setopt(listHandle, CURLOPT_HEADERFUNCTION, FtpCurl::wirteFile);
	curl_easy_setopt(listHandle, CURLOPT_HEADERDATA, respfile);
	CURLcode r = curl_easy_perform(listHandle);
	if (r != CURLE_OK)
	{
		m_strLastErrot = curl_easy_strerror(r);

		ret = -1;
	}
	curl_easy_cleanup(listHandle);

	fseek(ftpfile, 0, std::ios::end);
	strContent.resize(ftell(ftpfile));
	fseek(ftpfile, 0, std::ios::beg);
	fread(&strContent[0], 1, strContent.size(), ftpfile);

	fclose(respfile);
	fclose(ftpfile);
	return ret;
}

size_t FtpCurl::discard( void* ptr, size_t size, size_t nmemb, void* stream )
{
	return size * nmemb;
}

size_t FtpCurl::readFile( void* ptr, size_t size, size_t nmemb, void* stream )
{
	return fread(ptr, size, nmemb, (FILE*)stream) * size;
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
	std::string remotePaht = "ftp://";
	remotePaht.append(m_strFtpName);
	remotePaht.append(":");
	remotePaht.append(m_strFtpPassword);
	remotePaht.append("@");
	remotePaht.append(m_strFtpIPAddress);
	remotePaht.append(ftpPath);

	CURL* m_pCurlHandleDown = curl_easy_init();
	curl_easy_setopt(m_pCurlHandleDown, CURLOPT_URL, remotePaht.c_str());

	// 设置超时
	curl_easy_setopt(m_pCurlHandleDown, CURLOPT_CONNECTTIMEOUT, m_lTimeOut);

	// 设置头处理函数
	curl_easy_setopt(m_pCurlHandleDown, CURLOPT_HEADERFUNCTION, FtpCurl::contentlegth);

	// 获取长度值
	curl_easy_setopt(m_pCurlHandleDown, CURLOPT_HEADERDATA, &fileSize);

	// 写文件
	curl_easy_setopt(m_pCurlHandleDown, CURLOPT_WRITEFUNCTION, FtpCurl::wirteFile); 
	curl_easy_setopt(m_pCurlHandleDown, CURLOPT_WRITEDATA, file);
	curl_easy_setopt(m_pCurlHandleDown, CURLOPT_NOPROGRESS, 1L);
	curl_easy_setopt(m_pCurlHandleDown, CURLOPT_VERBOSE, 1L);
	CURLcode r = curl_easy_perform(m_pCurlHandleDown);

	fclose(file);
	if (r != CURLE_OK)
	{
		ret = -1;
		m_strLastErrot = curl_easy_strerror(r);
	}

	curl_easy_cleanup(m_pCurlHandleDown);
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
	std::string remotePaht = "ftp://";
	remotePaht.append(m_strFtpName);
	remotePaht.append(":");
	remotePaht.append(m_strFtpPassword);
	remotePaht.append("@");
	remotePaht.append(m_strFtpIPAddress);
	remotePaht.append(ftpPath);

	CURL* m_pCurlHandleUp = curl_easy_init();
	curl_easy_setopt(m_pCurlHandleUp, CURLOPT_UPLOAD, 1L);
	curl_easy_setopt(m_pCurlHandleUp, CURLOPT_URL, remotePaht.c_str());

	// 设置超时
	curl_easy_setopt(m_pCurlHandleUp, CURLOPT_FTP_RESPONSE_TIMEOUT, m_lTimeOut);

	curl_easy_setopt(m_pCurlHandleUp, CURLOPT_HEADERFUNCTION, FtpCurl::contentlegth);
	curl_easy_setopt(m_pCurlHandleUp, CURLOPT_HEADERDATA, &fileSize);
	curl_easy_setopt(m_pCurlHandleUp, CURLOPT_WRITEFUNCTION, FtpCurl::discard);

	// 读文件
	curl_easy_setopt(m_pCurlHandleUp, CURLOPT_READFUNCTION, FtpCurl::readFile);
	curl_easy_setopt(m_pCurlHandleUp, CURLOPT_READDATA, file);
	curl_easy_setopt(m_pCurlHandleUp, CURLOPT_FTPPORT, "-");
	curl_easy_setopt(m_pCurlHandleUp, CURLOPT_FTP_CREATE_MISSING_DIRS, 1L);
	curl_easy_setopt(m_pCurlHandleUp, CURLOPT_VERBOSE, 1L);
	
	CURLcode r = CURLE_GOT_NOTHING;
	for (int i = 0; r != CURLE_OK && i < m_lTrise; ++i)
	{
		if (i)
		{
			curl_easy_setopt(m_pCurlHandleUp, CURLOPT_NOBODY, 1L);
			curl_easy_setopt(m_pCurlHandleUp, CURLOPT_HEADER, 1L);
			r = curl_easy_perform(m_pCurlHandleUp);
			if (r != CURLE_OK)
			{
				continue;
			}
			curl_easy_setopt(m_pCurlHandleUp, CURLOPT_NOBODY, 0L);
			curl_easy_setopt(m_pCurlHandleUp, CURLOPT_HEADER, 0L);
			fseek(file, fileSize, SEEK_SET);
			curl_easy_setopt(m_pCurlHandleUp, CURLOPT_APPEND, 1L);
		}
		else
		{
			curl_easy_setopt(m_pCurlHandleUp, CURLOPT_APPEND, 0L);
		}

		r = curl_easy_perform(m_pCurlHandleUp);
	}

	fclose(file);
	if (r != CURLE_OK)
	{
		ret = -1;
		m_strLastErrot = curl_easy_strerror(r);
	}

	curl_easy_cleanup(m_pCurlHandleUp);
	return ret;
}
