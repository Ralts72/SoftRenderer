cmake_minimum_required(VERSION 3.31)
project(SoftRenderer)

set(CMAKE_CXX_STANDARD 20)
set(3RD_PATH ${PROJECT_SOURCE_DIR}/engine/3rdParty)

include_directories(${3RD_PATH}/googletest/googletest/include)
enable_testing()

add_subdirectory(app)
add_subdirectory(test)
add_subdirectory(engine/3rdParty/googletest)