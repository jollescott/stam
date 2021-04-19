cmake_minimum_required(VERSION 3.5)

project(stam LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(3rdparty/SDL)
add_subdirectory(3rdparty/glad)

add_executable(stam main.cpp
                    application.cpp
                    game.cpp
                    demogame.cpp
                    renderer.cpp
                    geometry.cpp
                    shader.cpp)

target_link_libraries(stam SDL2main SDL2-static glad)
