#include "../include/client.hpp"

int main() {
    std::string ip = "127.0.0.1"; 
    int port = 8080;             
    std::string client_id = "client2"; 

    Client client(ip, port, client_id); /
    client.start(); 

    return 0;
}



