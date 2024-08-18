cmake_minimum_required(VERSION 3.11)
project(
    bone
)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS include/calagen.hpp)
set(SOURCE include/calagen.cpp)

include(FindPkgConfig)
pkg_check_modules(LIBSSH REQUIRED libssh)


add_library(${PROJECT_NAME} 
    SHARED include/calagen.cpp
    include/calagen.hpp
)

target_include_directories(${PROJECT_NAME} 
    PRIVATE ${LIBSSH_INCLUDE_DIRS}
    PRIVATE ${CMAKE_BINARY_DIR}
)
target_link_libraries(${PROJECT_NAME} 
    PRIVATE ${LIBSSH_LIBRARIES}
)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${HEADERS}")

install(
    TARGETS ${PROJECT_NAME} 
    LIBRARY DESTINATION /usr/lib
    PUBLIC_HEADER DESTINATION /usr/include
)
install(DIRECTORY PUBLIC_HEADER DESTINATION include)

