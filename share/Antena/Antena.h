#pragma once
#include "C:\Users\1\source\repos\תעשיה אוורית תרגיל\share\Server\Server_Socket.h"
class Antena
{
public:
	Server_Socket server;
	Antena(int port) :server(port){
	}
};




