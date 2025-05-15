cmake_minimum_required(VERSION 3.31)
project(SoftRenderer)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES "*.cpp")

add_library(engine ${SOURCES})
target_link_libraries(engine PUBLIC ${SDL2_LIBRARIES})