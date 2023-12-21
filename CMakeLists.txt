cmake_minimum_required(VERSION 3.25)
project(Ceaser)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ceaser main.cpp
)

install(TARGETS Ceaser DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
