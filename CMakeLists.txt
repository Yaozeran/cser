cmake_minimum_required(VERSION 4.1.1)

project(cser)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} test/main.cc)
