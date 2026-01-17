cmake_minimum_required(VERSION 4.1.1)

project(cser LANGUAGES C CXX)

add_library(cser INTERFACE)

target_include_directories(cser
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(cser
  INTERFACE 
    cxx_std_23
)