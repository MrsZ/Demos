////
// File: FtpCurl.h
// Author:lyk
// Date: 2016/01/08
// Desc: Ftp服务上传下载功能
//
#ifndef FTPCURL_H
#define FTPCURL_H

#include <iostream>
#include "commonDef.h"

class FtpCurl
{
public:
	FtpCurl(void);
	~FtpCurl(void);

	void setConnect(const std::string& ftpName,
		const std::string& ftpPassword,
		const std::string& ftpIp,
		long timeout = 1, long trise = 3);

	void setProcess(DownInfo* info);
	std::string getLastError();

	// 下载，ftpPath：文件在ftp的路径，localPath本地存储位置
	int downLoad(const std::string& ftpPath, const std::string& localPath);

	// 上传，ftpPath：文件在ftp的路径，localPath本地存储位置
	int upLoad(const std::string& ftpPath, const std::string& localPath);

private:
	static size_t wirteFile(void *ptr, size_t size, size_t nmemb, void *data);
	static size_t contentlegth(void* ptr, size_t size, size_t nmemb, void* stream);
	static size_t discard(void* ptr, size_t size, size_t nmemb, void* stream);
	static size_t readFile(void* ptr, size_t size, size_t nmemb, void* stream);
	//这个函数是为了符合CURLOPT_PROGRESSFUNCTION而构造的
	//显示文件传输进度，t代表文件大小，d代表传 输已经完成部分
	static int progress(DownInfo *ptr, double t, double d, double ultotal, double ulnow);

private:
	long m_lTimeOut;                       // 超时连接
	long m_lTrise;                         // 连接次数
	std::string m_strFtpName;              // ftp登录用户名，如admin
	std::string m_strFtpPassword;          // ftp登录密码
	std::string m_strFtpIPAddress;         // ftp地址
	std::string m_strLastErrot;            // 错误信息
	DownInfo* m_pDownInfo;                        // 显示进度信息
};

#endif // FTPCURL_H
