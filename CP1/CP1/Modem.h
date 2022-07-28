#pragma once
#include "Server_Socket.h"
#include "Client.h"
class Modem
{
public:
	Server_Socket server;
	Modem(int port):server(port) {	
	}
};

