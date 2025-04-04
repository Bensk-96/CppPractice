cmake_minimum_required(VERSION 3.10)

project(smart_pointers_objects LANGUAGES CXX)

add_executable(smart_pointers_objects main.cpp)

set_property(TARGET smart_pointers_objects PROPERTY CXX_STANDARD 20)

install(TARGETS smart_pointers_objects CONFIGURATIONS Debug RUNTIME DESTINATION bin)