cmake_minimum_required(VERSION 2.8)

project(trapezoid_area)

set(SOURCE_EXE src/main.cpp)
set(SOURCE_LIB src/trapezium.cpp)


add_library(trapezium STATIC ${SOURCE_LIB})

add_executable(main ${SOURCE_EXE})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)


target_link_libraries(main trapezium Threads::Threads)











