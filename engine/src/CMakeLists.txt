cmake_minimum_required(VERSION 3.20)
project(Comet)
set(CMAKE_CXX_STANDARD 17)

set(LIBRARY_OUTPUT_PATH ${LIBPATH})

file(GLOB ENGINESRC 
    "*.cpp"
    "Math.h"
)

add_library(engine ${ENGINESRC})
target_link_libraries(engine PUBLIC sdl2)
