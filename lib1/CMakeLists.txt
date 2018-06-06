cmake_minimum_required(VERSION 3.9.6)
project(lib1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB SOURCES src/lib1.cpp)

add_library(lib1
  ${SOURCES}
)
IF (ANDROID)
find_library( # Defines the name of the path variable that stores the
            # location of the NDK library.
            log-lib

            # Specifies the name of the NDK library that
            # CMake needs to locate.
            log )
ENDIF() #ANDROID

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(lib1
                      Threads::Threads
                      # Links the log library to the target library.
                      ${log-lib}
                      )
