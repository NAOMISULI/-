#include "C:\Users\1\source\repos\����� ������ �����\share\IDD\IDD.h" 
#include "C:\Users\1\source\repos\����� ������ �����\share\Antena\Antena.h"
#include "C:\Users\1\source\repos\����� ������ �����\share\Modem\Modem.h"
#include "C:\Users\1\source\repos\����� ������ �����\share\Manager\Manager.h"
#include "C:\Users\1\source\repos\����� ������ �����\share\Amplifier\Amplifier.h"
#include<thread>
#include<vector>
#include <iostream>
using namespace std;

int main() {
    cout << RED << "CP1";
    cout << WHITE << endl;

    Antena antena = Antena(9000);
    Amplifier amplifier = Amplifier(8889);
    Modem modem = Modem(9002);
    vector<controlerType> Send_to;

    controlerType c1 = { MANAGER_TO_AMPLIFIER_CONTROL_MSG_OPCODE ,8889 };
    controlerType c2 = { MANAGER_TO_MODEM_CONTROL_MSG_OPCODE  ,9002 };
    controlerType c3 = { MANAGER_TO_ANTENNA_CONTROL_MSG_OPCODE  ,9000 };
    Send_to.push_back(c1);
    Send_to.push_back(c2);
    Send_to.push_back(c3);
    Manager manager = Manager(Send_to, 9004);
    while (true)
    {
        this_thread::sleep_for(std::chrono::seconds(1));
    }
}
