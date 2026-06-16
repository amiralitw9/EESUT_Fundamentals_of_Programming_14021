cmake_minimum_required(VERSION 3.26)
project(4)

set(CMAKE_CXX_STANDARD 17)

add_executable(4 main.cpp)
target_link_libraries(${PROJECT_NAME} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)
