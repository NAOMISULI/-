#include <iostream>
#include <winsock2.h>
#include"IDD.h"
#include "Server_Socket.h"
#define GREEN   "\033[32m"      /* Green */
#define WHITE   "\033[37m"      /* White */
using namespace std;

#pragma comment(lib,"ws2_32.lib") // Winsock Library
#pragma warning(disable:4996) 

#define BUFLEN 512
void Server_Socket::server()
{
    
    system("title UDP Server");

    sockaddr_in server, client;

    // initialise winsock
    WSADATA wsa;
    printf("Initialising Winsock...");
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("Failed. Error Code: %d", WSAGetLastError());
        exit(0);
    }
    printf("Initialised.\n");

    // create a socket
    SOCKET server_socket;
    if ((server_socket = socket(AF_INET, SOCK_DGRAM, 17)) == INVALID_SOCKET)
    {
        printf("Could not create socket: %d", WSAGetLastError());
    }
    printf("Socket created.\n");

    // prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // bind
    if (bind(server_socket, (sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
    {
        printf("Bind failed with error code: %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    puts("Bind done.");

    
    while (true)
    {
        printf("Waiting for data...");
        fflush(stdout);
       /* char message[BUFLEN] = {};*/
        char message[BUFLEN] = {};
       /* DataMessage message;*/


        // try to receive some data, this is a blocking call
        int message_len;
        int slen = sizeof(sockaddr_in);
        if (message_len = recvfrom(server_socket, message, BUFLEN, 0, (struct sockaddr*)&client, &slen) == SOCKET_ERROR)
        {
            printf("server failed with error code: %d\n", WSAGetLastError());
        }


        Header* h = (Header*)&message;
        if (h->Opcode != DATA_MSG_OPCODE) {
            ControlMessage* massage2 = (ControlMessage*)&message;
            if (massage2->Ack == 0)
                cout << "ack from " << massage2->header.Opcode << "is 0" << endl;
            // reply the client with 2the same data
        if (sendto(server_socket, (char*)&massage2, sizeof(massage2), 0,(sockaddr*)&client, sizeof(sockaddr_in)) == SOCKET_ERROR)
        {
            printf(" server sendto() failed with error code: %d\n", WSAGetLastError());
        }
        }
        else {
            DataMessage* massage = (DataMessage*)&massage;
            cout << GREEN << PORT <<"hello DataMessage from port "<< PORT<<endl;
            cout << WHITE;
            switch (PORT)
            {
            case(9004):client.sin_port = htons(9002);//modempc1
            case(9002):client.sin_port = htons(9009);//modempc2
            case(9009):client.sin_port = htons(9011);//menegerpc2
            case(9011):client.sin_port = htons(9008);//message generator
            case(9008):client.sin_port = htons(9004);//menegergpc1
            }
            if (sendto(server_socket, (char*)&message, strlen((char*)&message), 0, (sockaddr*)&client, sizeof(sockaddr_in)) == SOCKET_ERROR)
            {
                printf("server sendto() failed with error code: %d\n", WSAGetLastError());
            }
            /*return 0;*/
        }
       /* printf("Data: %d\n",(DataMessage*)&message.header.msgCounter);*/

       /* cin.getline(message, BUFLEN);*/

        
    }

    closesocket(server_socket);
    WSACleanup();
}
