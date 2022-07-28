#pragma once
//For Data messages
#define DATA_MSG_OPCODE 0xD001
//For Control Messages
#define MANAGER_TO_AMPLIFIER_CONTROL_MSG_OPCODE  0xA002
#define AMPLIFIER_TO_MANAGER_CONTROL_MSG_OPCODE  0xA003
#define MANAGER_TO_MODEM_CONTROL_MSG_OPCODE 0xA004
#define MODEM_TO_MANAGER_CONTROL_MSG_OPCODE 0xA005
#define MANAGER_TO_ANTENNA_CONTROL_MSG_OPCODE 0xA006
#define ANTENNA_TO_MANAGER_CONTROL_MSG_OPCODE 0xA007
#define MSG_SYNC 0xAA55


//#define ANTENA_PORT 9000
//#define AMPLIFIER_PORT 8889
//#define MODEM_PORT=9002


using namespace std;
typedef struct {
    unsigned short msgSync;
    unsigned short Opcode;
    unsigned int msgCounter;
} Header;
typedef struct {
    Header header;
    char Ack;
}ControlMessage;
typedef struct {
    Header header;
}DataMessage;
typedef struct {
    int to;
    int port;
    int counter=0;
}controlerType;

