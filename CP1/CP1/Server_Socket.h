#pragma once
#include<thread>
using namespace std;


class Server_Socket
{
public:
	int PORT;
	void server();
	Server_Socket(int port) {
		PORT = port;
		thread t1(&Server_Socket::server, this);
		t1.detach();
	}
};

