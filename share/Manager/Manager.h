#pragma once
#include "C:\Users\1\source\repos\תעשיה אוורית תרגיל\share\IDD\IDD.h" 
#include "C:\Users\1\source\repos\תעשיה אוורית תרגיל\share\Client\Client.h"
#include "C:\Users\1\source\repos\תעשיה אוורית תרגיל\share\Server\Server_Socket.h"
#include<thread>
#include<vector>
#include <unordered_map>
#include<thread>
#include <iostream>
using namespace std;

//#include <under>
class Manager
{
public:
	int flag = 0;
	Client c ;
	vector<controlerType> m;
	vector<controlerType> Send_to;
	Manager(vector<controlerType> Send_to1,int port) {
		Server_Socket server = Server_Socket(port);
		Client c = Client();
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


void Manager::get_Massag()
{
	while (true)
	{
		c.send_client(Send_to);
		for (int i = 0; i < Send_to.size(); i++)
		{
			Send_to[i].counter = c.Client_counter;
			m.push_back(Send_to[i]);
		}
		flag = 1;
		this_thread::sleep_for(std::chrono::seconds(1));
		c.Client_counter++;
	}
}

void Manager::rec_get_Massag()
{
	while (true)
	{
		if (flag) {
			Header massage = c.recivd_client(Send_to);
			for (int i = 0; i < m.size(); i++)
			{
				if (m[i].counter == massage.msgCounter && m[i].to == massage.Opcode)
					m.erase(m.begin() + i);
			}
		}
	}

}

void Manager::chach()
{
	while (true) {
		/*this_thread::sleep_for(std::chrono::seconds(5));*/
		if (c.Client_counter % 5 == 0) {
			for (int i = 0; i < m.size(); i++)
			{
				if (c.Client_counter - (m[i].counter) > 5)
				{
					/*cout << GREEN;*/
					cout << "error in sec " << m[i].counter << " in port " << m[i].port;
					/*cout << WHITE << endl;*/
					m.erase(m.begin() + i);
				}
			}
		}	
	}
}

