cmake_minimum_required(VERSION 3.8)
project(P2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp scanner.cpp scanner.h token.cpp token.cpp util.cpp util.h parser.cpp parser.h node.cpp node.h)
add_executable(P2 ${SOURCE_FILES})