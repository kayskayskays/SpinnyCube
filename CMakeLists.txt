cmake_minimum_required(VERSION 3.24)
project(Cube)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)
add_executable(Cube ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio required)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Cube sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
