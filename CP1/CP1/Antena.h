#pragma once
#include "IDD.h" 
#include "Server_Socket.h"
class Antena
{
public:
	Server_Socket server;
	Antena(int port) :server(port){
	}
};

