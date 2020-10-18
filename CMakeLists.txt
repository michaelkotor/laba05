cmake_minimum_required(VERSION 3.17)
project(laba05)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(laba05
        include/Bussines.h
        include/IP.h
        include/Man.h
        include/Tourist.h
        src/Bussines.cpp
        src/IP.cpp
        src/Man.cpp
        src/Tourist.cpp
        CMakeLists.txt
        main.cpp)
