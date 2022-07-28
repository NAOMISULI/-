#pragma once
#include "C:\Users\1\source\repos\תעשיה אוורית תרגיל\share\Server\Server_Socket.h"
class Amplifier
{
public:
	Server_Socket server;
	Amplifier(int port):server(port) {
	}
};

