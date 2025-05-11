cmake_minimum_required(VERSION 3.31)
project(SoftRenderer)

set(CMAKE_CXX_STANDARD 20)
set(THIRD_PARTY_PATH ${PROJECT_SOURCE_DIR}/engine/3rdParty)

find_package(SDL2 REQUIRED)
if(NOT SDL2_FOUND)
    message(FATAL_ERROR "SDL2 not found, please install it.")
endif()

include_directories(
        ${THIRD_PARTY_PATH}/googletest/googletest/include
        engine/src
        ${SDL2_INCLUDE_DIRS}
)
enable_testing()

add_subdirectory(app)
add_subdirectory(test)
add_subdirectory(engine/src)
add_subdirectory(engine/3rdParty/googletest)