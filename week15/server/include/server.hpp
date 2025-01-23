#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <string>
#include <map>
#include <netinet/in.h>
#include <thread>
#include <mutex>
#include <queue>
#include <unistd.h>
#include <cstring>
#include <chrono>
#include <condition_variable>

#define MAX_CLIENTS 10

class Server {
public:
    Server(int port);
    void start();

private:
    int server_fd, opt, port;
    struct sockaddr_in address;
    socklen_t addrlen;

    std::map<std::string, int> clients; // ID клиента и его сокет
    std::mutex clients_mutex;

    std::queue<std::pair<std::string, std::string>> task_queue; // Очередь задач
    std::mutex task_mutex;
    std::condition_variable task_queue_cv;

    void handleClient(int client_socket);
    void processTasks();
    void processTask(const std::string& hash, const std::string& client_id);
    void inputLoop(); // Новый метод для обработки ввода
};

#endif // SERVER_HPP







