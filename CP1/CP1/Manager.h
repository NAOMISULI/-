#pragma once
#include "IDD.h"
#include "Client.h"
#include "Server_Socket.h"
#include<thread>
#include<vector>
#include <unordered_map>
using namespace std;

//#include <under>
class Manager
{
public:
	int flag = 0;
	vector<controlerType> Send_to;
	//controlerType c1 = { MANAGER_TO_AMPLIFIER_CONTROL_MSG_OPCODE ,8889 };
	//controlerType c2 = { MANAGER_TO_MODEM_CONTROL_MSG_OPCODE  ,9002 };
	//controlerType c3 = { MANAGER_TO_ANTENNA_CONTROL_MSG_OPCODE  ,9000 };
	Client c ;
	Server_Socket server = Server_Socket(9004);
	vector<controlerType> m;
	Manager(vector<controlerType> Send_to1) {
		Client c = Client();
		//Send_to.push_back(c1);
		//Send_to.push_back(c2);
		//Send_to.push_back(c3);
		Send_to = Send_to1;
		thread t1(&Manager::get_Massag,this);
		thread t2(&Manager::rec_get_Massag, this);
		thread t3(&Manager::chach, this);
		t1.detach();
		t2.detach();
		t3.detach();
		this_thread::sleep_for(std::chrono::seconds(1));


	}
	void get_Massag();
	void rec_get_Massag();
	void chach();
};

