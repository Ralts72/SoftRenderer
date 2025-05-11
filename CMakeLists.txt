cmake_minimum_required(VERSION 3.31)
project(SoftRenderer)

set(CMAKE_CXX_STANDARD 20)
set(3RDPATH ${PROJECT_SOURCE_DIR}/engine/3rdParty)

#include_directories(app)
add_executable(SoftRenderer app/main.cpp
        test/test.cpp)
add_subdirectory(app)