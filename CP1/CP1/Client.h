#pragma once
#include <vector>
#include"IDD.h"
#include <winsock2.h>
#include<unordered_map>

class Client
{
public:
	/*vector<controlerType> Send_to;*/
	sockaddr_in server;
	int client_socket;
	/*int PORT;*/
	int Client_counter;
	int Create_Client();
	Client() {
		Client_counter = 0;
		client_socket = -1;
		Create_Client();
	}
	void send_client(vector<controlerType> Send_to);
	Header recivd_client(vector<controlerType> Send_to);
};

