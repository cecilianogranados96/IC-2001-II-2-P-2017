#include "Server.h"
#include <iostream>
using namespace std;
//################################
//#
//# OBJETIVO:
//# =========
//#
//# Contrucción del socket.
//#
//#
//# Desarrollo:
//#
//# - Jose Andres Ceciliano
//#
//#
//################################
WSockServer::WSockServer()
{
	hSocket = INVALID_SOCKET;
	ClientSocket = INVALID_SOCKET;
	if(WSAStartup(MAKEWORD(2, 0), &wsaData) == 0)
	{
		if(LOBYTE(wsaData.wVersion < 2))
		{
			throw "Error de inicio del Winsock.";
		}
	}
	else
		throw "Inicio con fallos, puerto blockeado.";
}

void WSockServer::SetServerSockAddr(sockaddr_in *sockAddr)
{
	sockAddr->sin_family = AF_INET;
	sockAddr->sin_port = htons(1500);
	sockAddr->sin_addr.S_un.S_addr = INADDR_ANY;
}

string WSockServer::RunServer(string text)
{
	if((hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
		throw "No se puede crear el socket.";
	SetServerSockAddr(&sockAddr);
	if(bind(hSocket, (sockaddr*)(&sockAddr), sizeof(sockAddr)) != 0)
		throw "No se puede conectar al socket.";
	if(listen(hSocket, SOMAXCONN) != 0)
		throw "No se puede colocar el socket en listen.";
	int SizeAddr = sizeof(ClientAddr);
	cout << "Waith... ";
	ClientSocket = accept(hSocket, (sockaddr*)(&ClientAddr), &SizeAddr);
	cout << "CON: ";
    int BytesRec = recv(ClientSocket, Buffer, sizeof(Buffer), 0);
    Buffer[BytesRec] = 0;
	cout << "RES: " << Buffer;
    closesocket(hSocket);
    send2(text);
    cout << "\n";
	return Buffer;
}

void WSockServer::send2(string str)
{
    char * writable = new char[str.size() + 1];
    copy(str.begin(), str.end(), writable);
    writable[str.size()] = '\0';
    send(ClientSocket, writable, str.size()+1, 1);
    delete[] writable;
}

WSockServer::~WSockServer()
{
	if(WSACleanup() != 0)
		throw "Error al limpiar el socket.";
	if(hSocket != INVALID_SOCKET)
		closesocket(hSocket);
	if(ClientSocket != INVALID_SOCKET)
		closesocket(hSocket);
}
