#include <iostream>
#include "FtpCurl.h"

int main(int argc, char **argv)
{
	FtpCurl curl;
	curl.setConnect("admin", "123456", "192.168.3.91/Apps/");
	int ret = 0;
	ret = curl.downLoad("1111.doc", "D:\\1111.doc");
	std::string strErr;
	if (ret)
	{
		strErr = curl.getLastError();
	}
	ret = curl.upLoad("2222.docx", "D:\\2222.docx");
	if (ret)
	{
		strErr = curl.getLastError();
	}
	return 0;
}
