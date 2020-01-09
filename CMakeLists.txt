cmake_minimum_required(VERSION 2.8)
project(meta)

set(CMAKE_CXX_STANDARD 14)

add_executable(meta src/main.cpp src/Airport.cpp src/Airport.h src/Greedy.cpp src/Greedy.h src/LocalSearch.cpp src/LocalSearch.h src/Utils.cpp src/Utils.h src/TabuSearch.cpp src/TabuSearch.h)