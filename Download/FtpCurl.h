////
// File: FtpCurl.h
// Author:lyk
// Date: 2016/01/08
// Desc: Ftp�����ϴ����ع���
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

	// ���أ�ftpPath���ļ���ftp��·����localPath���ش洢λ��
	int downLoad(const std::string& ftpPath, const std::string& localPath);

	// �ϴ���ftpPath���ļ���ftp��·����localPath���ش洢λ��
	int upLoad(const std::string& ftpPath, const std::string& localPath);

private:
	static size_t wirteFile(void *ptr, size_t size, size_t nmemb, void *data);
	static size_t contentlegth(void* ptr, size_t size, size_t nmemb, void* stream);
	static size_t discard(void* ptr, size_t size, size_t nmemb, void* stream);
	static size_t readFile(void* ptr, size_t size, size_t nmemb, void* stream);
	//���������Ϊ�˷���CURLOPT_PROGRESSFUNCTION�������
	//��ʾ�ļ�������ȣ�t�����ļ���С��d���� ���Ѿ���ɲ���
	static int progress(DownInfo *ptr, double t, double d, double ultotal, double ulnow);

private:
	long m_lTimeOut;                       // ��ʱ����
	long m_lTrise;                         // ���Ӵ���
	std::string m_strFtpName;              // ftp��¼�û�������admin
	std::string m_strFtpPassword;          // ftp��¼����
	std::string m_strFtpIPAddress;         // ftp��ַ
	std::string m_strLastErrot;            // ������Ϣ
	DownInfo* m_pDownInfo;                        // ��ʾ������Ϣ
};

#endif // FTPCURL_H
