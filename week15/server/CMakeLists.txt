cmake_minimum_required(VERSION 3.10)

project(Server)

include_directories(include)

find_package(OpenSSL REQUIRED)

add_executable(server src/server.cpp src/main.cpp)
target_link_libraries(server OpenSSL::Crypto)



