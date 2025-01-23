#include "server.hpp"

Server::Server(int port) : port(port) {
    opt = 1;
    addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        std::cerr << "Ошибка при создании сокета" << std::endl;
        exit(EXIT_FAILURE);
    }

    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Ошибка при привязке сокета" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        std::cerr << "Ошибка при прослушивании" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Server::start() {
    std::cout << "Сервер запущен на порту " << port << std::endl;

    std::thread(&Server::processTasks, this).detach();
    std::thread(&Server::inputLoop, this).detach(); 

    while (true) {
        int client_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen);
        if (client_socket >= 0) {
            std::cout << "Новый клиент подключился" << std::endl;
            std::thread(&Server::handleClient, this, client_socket).detach();
        }
    }
}

void Server::handleClient(int client_socket) {
    char buffer[1024] = {0};
    int bytes_read;

    
    bytes_read = read(client_socket, buffer, sizeof(buffer));
    if (bytes_read <= 0) {
        std::cerr << "Ошибка при чтении ID клиента" << std::endl;
        close(client_socket);
        return;
    }
    std::string client_id(buffer, bytes_read);

    
    {
        std::lock_guard<std::mutex> lock(clients_mutex);
        clients[client_id] = client_socket;
    }

    std::cout << "Клиент " << client_id << " подключился." << std::endl;

    
    while (true) {
        char msg_buffer[1024] = {0};
        int msg_bytes_read = read(client_socket, msg_buffer, sizeof(msg_buffer));
        if (msg_bytes_read <= 0) {
            std::cerr << "Клиент " << client_id << " отключился." << std::endl;
            close(client_socket);
            break;
        }
        
        
        std::string message(msg_buffer, msg_bytes_read);
        std::cout << "Сообщение от " << client_id << ": " << message << std::endl;
    }
}

void Server::processTasks() {
    while (true) {
        std::pair<std::string, std::string> task;

        {
            std::unique_lock<std::mutex> lock(task_mutex);
            task_queue_cv.wait(lock, [this] { return !this->task_queue.empty(); });
            if (!task_queue.empty()) {
                task = task_queue.front();
                task_queue.pop();
            }
        }

        processTask(task.first, task.second);
    }
}

void Server::processTask(const std::string& hash, const std::string& client_id) {
    std::lock_guard<std::mutex> lock(clients_mutex);
    if (clients.find(client_id) != clients.end()) {
        int client_socket = clients[client_id];
        if (send(client_socket, hash.c_str(), hash.length(), 0) < 0) {
            std::cerr << "Ошибка при отправке хэша клиенту" << std::endl;
            return;
        }

        char resultBuffer[1024] = {0};
        int bytesRead = read(client_socket, resultBuffer, sizeof(resultBuffer));
        if (bytesRead > 0) {
            std::string result(resultBuffer, bytesRead);
            std::cout << "Результат от клиента " << client_id << ": " << result << std::endl;
        } else {
            std::cerr << "Ошибка при чтении результата от клиента" << std::endl;
        }
    } else {
        std::cerr << "Клиент " << client_id << " не найден." << std::endl;
    }
}

void Server::inputLoop() {
    while (true) {
        std::string hash;
        std::cout << "Введите хэш (или 0 для выхода): ";
        std::cin >> hash;

        if (hash == "0") {
            std::cout << "Сервер завершает работу..." << std::endl;
            exit(0);
        }

        std::string target_client;
        std::cout << "Введите ID клиента: ";
        std::cin >> target_client;

        {
            std::lock_guard<std::mutex> lock(task_mutex);
            task_queue.emplace(hash, target_client);
            task_queue_cv.notify_one(); 
        }
    }
}






