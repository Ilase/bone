cmake_minimum_required(VERSION 3.10)
project(
    example
    VERSION 1.0.0
)

find_package(bone 1.0 REQUIRED)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC bone
)
