cmake_minimum_required(VERSION 3.10)
project(cxx_lox LANGUAGES CXX)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(
  lox
  src/main.cpp
  src/lox.cpp
  src/token.cpp
  src/scanner.cpp
)
