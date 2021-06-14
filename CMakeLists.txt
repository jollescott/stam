cmake_minimum_required(VERSION 3.5)

project(stam LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(3rdparty/glad)
add_subdirectory(3rdparty/glm)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(stam main.cpp
                    application.cpp
                    game.cpp
                    demogame.cpp
                    shader.cpp
                    geometry.cpp)

target_link_libraries(stam ${SDL2_LIBRARIES} ${CMAKE_DL_LIBS} glad glm)
