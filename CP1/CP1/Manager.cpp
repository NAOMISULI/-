#include "Manager.h"
#include<thread>
#include "IDD.h"
#include <iostream>
using namespace std;

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
		this_thread::sleep_for(std::chrono::seconds(5));
		for (int i = 0; i < m.size(); i++)
		{
			if (c.Client_counter - (m[i].counter) > 5)
			{
				cout<< "error in " << m[i].counter << "sec in port" << m[i].to;
				m.erase(m.begin() + i);
			}
		}
	}	
}
