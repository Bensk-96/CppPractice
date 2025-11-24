cmake_minimum_required(VERSION 3.10)

project(virtual_destructor LANGUAGES CXX)

add_executable(virtual_destructor main.cpp)

set_property(TARGET virtual_destructor PROPERTY CXX_STANDARD 20)

install(TARGETS virtual_destructor CONFIGURATIONS Debug RUNTIME DESTINATION bin)