cmake_minimum_required(VERSION 3.10)

project(helloworld LANGUAGES CXX)

add_executable(helloworld helloworld.cpp)

set_property(TARGET helloworld PROPERTY CXX_STANDARD 20)

install(TARGETS helloworld CONFIGURATIONS Debug RUNTIME DESTINATION bin)