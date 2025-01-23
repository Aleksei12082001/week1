#include "../include/client.hpp"
#include <arpa/inet.h> // Для inet_pton
#include <unistd.h>    // Для close()
#include <cstring>     // Для memset()
#include <iostream>

Client::Client(const std::string& ip, int port, const std::string& id) : id(id) {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Ошибка при создании сокета" << std::endl;
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip.c_str(), &server_addr.sin_addr) <= 0) {
        std::cerr << "Ошибка: неверный IP-адрес" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Client::start() {
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Ошибка при подключении к серверу" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Отправляем ID клиента на сервер
    send(sock, id.c_str(), id.length(), 0);

    std::cout << "Клиент подключен с ID: " << id << std::endl;

    while (true) {
        processTask();
    }
}

void Client::processTask() {
    char buffer[1024] = {0};

    // Принимаем задачу (хэш) от сервера
    int bytes_read = read(sock, buffer, sizeof(buffer));
    if (bytes_read <= 0) {
        std::cerr << "Ошибка при получении задачи от сервера" << std::endl;
        close(sock);
        exit(EXIT_FAILURE);
    }

    std::string hash(buffer, bytes_read);
    std::cout << "Получена задача: " << hash << std::endl;

    // Вычисляем длину пароля (8 символов для MD5)
    int password_length = (hash.length() == 32) ? 8 : 0;
    std::string result = std::to_string(password_length);

    // Отправляем результат обратно серверу
    send(sock, result.c_str(), result.length(), 0);
}




