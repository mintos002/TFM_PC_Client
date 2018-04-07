#ifndef SEND_DATA_H
#define SEND_DATA_H

#include "print_out.h"
#include "data_handler.h"

#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <fcntl.h>
#include <sys/types.h>

class SendData {
public:
    SendData(std::string host);
    bool connected;
    DataHandler* robot_state;
    bool start();
    void halt();
    std::string receive(int);
private:
    int pri_sockfd, sec_sockfd; // port number
    struct sockaddr_in pri_serv_addr, sec_serv_addr; // sockets
    struct hostent *server; //  server IP
    bool keepalive;
    std::thread comThread;
    int flag;
    void run();
};

#endif /* SEND_DATA_H */