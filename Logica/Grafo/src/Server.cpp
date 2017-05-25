#include "Server.h"
#include <iostream>
using namespace std;
WSockServer::WSockServer(int REQ_WINSOCK_VER = 2 )
{
	hSocket = INVALID_SOCKET;
	ClientSocket = INVALID_SOCKET;
	if(WSAStartup(MAKEWORD(REQ_WINSOCK_VER, 0), &wsaData) == 0)		// Check required version
	{
		if(LOBYTE(wsaData.wVersion < REQ_WINSOCK_VER))
		{
			throw "Error de inicio del Winsock.";
		}
	}
	else
		throw "Inicio con fallos, puerto blockeado.";
}

void WSockServer::SetServerSockAddr(sockaddr_in *sockAddr, int PortNumber)
{
	sockAddr->sin_family = AF_INET;
	sockAddr->sin_port = htons(PortNumber);
	sockAddr->sin_addr.S_un.S_addr = INADDR_ANY;			// Listen on all available ip's
}


string WSockServer::RunServer(int PortNumber,string text)
{
	if((hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)		// Create socket
		throw "No se puede crear el socket.";
	SetServerSockAddr(&sockAddr, PortNumber);										// Fill sockAddr
	if(bind(hSocket, (sockaddr*)(&sockAddr), sizeof(sockAddr)) != 0)
		throw "No se puede conectar al socket.";
	if(listen(hSocket, SOMAXCONN) != 0)
		throw "No se puede colocar el socket en listen.";
	/*
	cout << "INICIO: " << endl;
	cout << "IP: " << inet_ntoa(sockAddr.sin_addr) << endl;
	cout << "PUERTO: " << ntohs(sockAddr.sin_port) << endl << endl;
	*/
	int SizeAddr = sizeof(ClientAddr);
	cout << "Waith... ";
	ClientSocket = accept(hSocket, (sockaddr*)(&ClientAddr), &SizeAddr);
	cout << "Conect: ";

    int BytesRec = recv(ClientSocket, Buffer, sizeof(Buffer), 0);
    Buffer[BytesRec] = 0;
	cout << "OPT: " << Buffer;
    closesocket(hSocket);
    send2(text);

	return Buffer;
}


void WSockServer::send2(string str)
{
    char * writable = new char[str.size() + 1];
    copy(str.begin(), str.end(), writable);
    writable[str.size()] = '\0'; // don't forget the terminating 0
    send(ClientSocket, writable, str.size()+1, 1);
    cout << " RES: "<< writable  <<endl;
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
