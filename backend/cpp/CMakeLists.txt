project(energy_simulation)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(energy_simulation ${SOURCES})