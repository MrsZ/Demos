////
// File: FtpCurl.h
// Author:lyk
// Date: 2016/01/08
// Desc:
//
#ifndef FTPCURL_H
#define FTPCURL_H

#include <iostream>
#include "curl/curl.h"

class FtpCurl
{
public:
	FtpCurl(void);
	~FtpCurl(void);

	void setConnect(const std::string& ftpName,
		const std::string& ftpPassword,
		const std::string& ftpIp,
		long timeout = 1, long trise = 3);

	std::string getLastError();

	// 下载，ftpPath：文件在ftp的路径，localPath本地存储位置
	int downLoad(const std::string& ftpPath, const std::string& localPath);

	// 上传，ftpPath：文件在ftp的路径，localPath本地存储位置
	int upLoad(const std::string& ftpPath, const std::string& localPath);

private:
	CURL* m_pCurlHandle;
	long m_lTimeOut;                       // 超时连接
	long m_lTrise;                         // 连接次数
	std::string m_strFtpName;              // ftp登录用户名，如admin
	std::string m_strFtpPassword;          // ftp登录密码
	std::string m_strFtpIPAddress;         // ftp地址
	std::string m_strLastErrot;            // 错误信息
};

#endif // FTPCURL_H
