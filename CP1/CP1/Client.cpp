#include "Client.h"
#include <iostream>
#include <winsock2.h>
#include "IDD.h"
#include<thread>
using namespace std;

#pragma comment(lib,"ws2_32.lib") 
#pragma warning(disable:4996) 

#define SERVER "192.168.150.3"  // or "localhost" - ip address of UDP server
#define BUFLEN 512  // max length of answer
//#define PORT 8888  // the port on which to listen for incoming data
#define MSG_SYNC 0xAA55
#define DATA_MSG_OPCODE 0xD001



int Client::Create_Client()
{

    system("title UDP Client");

    // initialise winsock
    WSADATA ws;
    printf("Initialising Winsock...");
    if (WSAStartup(MAKEWORD(2, 2), &ws) != 0)
    {
        printf("Failed. Error Code: %d", WSAGetLastError());
        return 1;
    }
    printf("Initialised.\n");

    // create socket
    /*int client_socket;*/
    if ((client_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR) // <<< UDP socket
    {
        printf("socket() failed with error code: %d", WSAGetLastError());
        return 2;
    }

    // setup address structure
    memset((char*)&server, 0, sizeof(server));
    server.sin_family = AF_INET;
   /* server.sin_port = htons(PORT);*/
    server.sin_addr.S_un.S_addr = inet_addr(SERVER);
}


void Client::send_client(vector<controlerType> Send_to) {
    ControlMessage message;
    message.Ack = 1;
    message.header.msgSync = MSG_SYNC;
    message.header.msgCounter = Client_counter;
        for (int i = 0; i < Send_to.size(); i++)
        {
            message.header.Opcode = Send_to[i].to;
            server.sin_port = htons(Send_to[i].port);
            cout<< Send_to[i].port;
            if (sendto(client_socket, (char*)&message, sizeof(message), 0, (sockaddr*)&server, sizeof(sockaddr_in)) == SOCKET_ERROR)
            {
                printf("send_client sendto() failed with error code: %d\n", WSAGetLastError());
          
            }
            else {
                printf("send_client sucsess\n");
            }
        }
        Client_counter++;
    /*_sleep(1);*/
}

Header Client::recivd_client(vector<controlerType> Send_to)
{
   
        for (int i = 0; i < Send_to.size(); i++)
        {
            //receive a reply and print it
           //clear the answer by filling null, it might have previously received data
            char message[BUFLEN] = {};
            //try to receive some data, this is a blocking call
            int slen = sizeof(sockaddr_in);
            int answer_length;
            if (answer_length = recvfrom(client_socket, message, BUFLEN, 0, (sockaddr*)&server, &slen) == SOCKET_ERROR)
            {
                printf(" recivd_client >>recvfrom() failed with error code: %d\n", WSAGetLastError());
              /*  exit(0);*/
            }
            else {
                printf(" recivd_client sucss\n");
            }
            Header* h = (Header*)&message;
            
            if (h->Opcode != DATA_MSG_OPCODE) {
                ControlMessage* massage2 = (ControlMessage*)&message;
                return massage2->header;
            }
        }
        /*cout << answer << "\n";*/
   //chac which type is the massage
    
}

