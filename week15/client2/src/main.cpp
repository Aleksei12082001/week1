#include "../include/client.hpp"

int main() {
    std::string ip = "127.0.0.1"; // IP-адрес сервера
    int port = 8080;             // Порт сервера
    std::string client_id = "client2"; // Уникальный идентификатор второго клиента

    Client client(ip, port, client_id); // Создаем объект клиента с уникальным ID
    client.start(); // Запускаем клиента

    return 0;
}



