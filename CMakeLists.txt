cmake_minimum_required(VERSION 3.18)

project(aton)

set(CMAKE_CXX_STANDARD 20)


find_package(raylib REQUIRED)

add_executable(bounce src/main.cpp)
target_link_libraries(bounce PRIVATE raylib)


set_target_properties(bounce PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bounce
)
