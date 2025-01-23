#include "../include/client.hpp"

int main() {
    std::string ip = "127.0.0.1";
    int port = 8080;
    std::string client_id = "client1"; // Добавляем идентификатор клиента

    Client client(ip, port, client_id); // Передаем три аргумента
    client.start();

    return 0;
}








