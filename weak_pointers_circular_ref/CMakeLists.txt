cmake_minimum_required(VERSION 3.10)

project(weak_pointers_circular_ref LANGUAGES CXX)

add_executable(weak_pointers_circular_ref main.cpp)

set_property(TARGET weak_pointers_circular_ref PROPERTY CXX_STANDARD 20)

install(TARGETS weak_pointers_circular_ref CONFIGURATIONS Debug RUNTIME DESTINATION bin)