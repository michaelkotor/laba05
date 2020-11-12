cmake_minimum_required(VERSION 3.17)
project(laba05)

set(CMAKE_CXX_STANDARD 20)

#set(CMAKE_CXX_FLAGS "-Werror -Wall ")
set(CMAKE_CXX_COMPILER clang++)

include_directories(include)

add_executable(laba05
        include/Bussines.h
        include/IP.h
        include/Man.h
        include/Tourist.h
        include/CustomException.h
        include/ValidateString.h
        include/InputException.h
        src/Bussines.cpp
        src/IP.cpp
        src/Man.cpp
        src/Tourist.cpp
        CMakeLists.txt
        main.cpp
        src/CustomException.cpp
        src/InputException.cpp
        src/ValidateString.cpp
        include/Queue.h src/Iterator.cpp include/Iterator.h include/Node.h include/Collections.h)
