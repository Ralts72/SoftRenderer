cmake_minimum_required(VERSION 3.20)
project(SoftRenderer)
set(CMAKE_CXX_STANDARD 17)

set(OUTPATH ${PROJECT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE})
set(LIBPATH ${PROJECT_SOURCE_DIR}/lib)
set(3RDPATH ${PROJECT_SOURCE_DIR}/engine/3rdParty)
set(SDL_DIR /opt/homebrew/Cellar/sdl2/2.32.4)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG)
endif()

include_directories(
    ${SDL_DIR}/include 
    # ${3RDPATH}/glfw/include
    # ${3RDPATH}/spdlog/include
#     engine/3rdParty/assimp/include
#     engine/3rdParty
    # ${Vulkan_INCLUDE_DIRS}
)
link_directories(${SDL_DIR}/lib/)

add_subdirectory(engine/src)
add_subdirectory(app)