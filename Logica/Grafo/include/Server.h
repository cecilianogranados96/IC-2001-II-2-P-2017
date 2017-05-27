#ifndef __SERVER_H__
#define __SERVER_H__
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <iostream>
using namespace std;
class WSockServer
{
public:
	WSockServer();
	~WSockServer();
	string RunServer(string text);
	void send2(string thestring);
	void SetServerSockAddr(sockaddr_in *sockAddr);
private:
    char Buffer[128];
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKET ClientSocket;
	sockaddr_in sockAddr;
	sockaddr_in ClientAddr;
};
#endif
