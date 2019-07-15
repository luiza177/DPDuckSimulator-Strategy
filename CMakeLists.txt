cmake_minimum_required(VERSION 3.15)

Project(DuckSimulation)

include_directories(include)

add_executable(DuckSimulator src/main.cpp)
add_executable(DuckSimSmart src/mainSmart.cpp)