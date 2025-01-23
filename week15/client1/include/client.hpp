#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <string>
#include <netinet/in.h>

class Client {
public:
    Client(const std::string& ip, int port, const std::string& id);
    void start();

private:
    int sock;
    std::string id;
    struct sockaddr_in server_addr;

    void processTask();
};

#endif // CLIENT_HPP







