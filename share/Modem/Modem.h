#pragma once
#include "C:\Users\1\source\repos\תעשיה אוורית תרגיל\share\Server\Server_Socket.h"
class Modem
{
public:
	Server_Socket server;
	Modem(int port) :server(port) {
	}
};


