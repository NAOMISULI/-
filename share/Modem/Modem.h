#pragma once
#include "C:\Users\1\source\repos\����� ������ �����\share\Server\Server_Socket.h"
class Modem
{
public:
	Server_Socket server;
	Modem(int port) :server(port) {
	}
};


