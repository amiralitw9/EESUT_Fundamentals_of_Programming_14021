cmake_minimum_required(VERSION 3.26)
project(_5)

set(CMAKE_CXX_STANDARD 23)

add_executable(_5 main.cpp)
target_link_libraries(${PROJECT_NAME} -lconio)
target_link_libraries(${PROJECT_NAME} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)

