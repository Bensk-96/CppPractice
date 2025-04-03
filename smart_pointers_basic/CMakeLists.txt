cmake_minimum_required(VERSION 3.10)

project(smart_pointers_basic LANGUAGES CXX)

add_executable(smart_pointers_basic smart_pointers_basic.cpp)

set_property(TARGET smart_pointers_basic PROPERTY CXX_STANDARD 20)

install(TARGETS smart_pointers_basic CONFIGURATIONS Debug RUNTIME DESTINATION bin)