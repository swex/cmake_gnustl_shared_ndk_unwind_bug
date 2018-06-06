cmake_minimum_required(VERSION 3.9.6)
project(lib2)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB SOURCES src/lib2.cpp)
include_directories(../lib1/src)
add_library(lib2
  ${SOURCES}
)

find_package(Threads REQUIRED)
target_link_libraries(lib2
                      lib1
                      )
