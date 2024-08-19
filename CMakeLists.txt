cmake_minimum_required(VERSION 3.11)
project(
    bone
    VERSION 1.0.0
)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS include/bone/calagen.hpp)
set(SOURCE src/bone/calagen.cpp)

include(FindPkgConfig)
pkg_check_modules(LIBSSH REQUIRED libssh)


add_library(${PROJECT_NAME} 
    SHARED src/bone/calagen.cpp
    include/bone/calagen.hpp
)

target_include_directories(${PROJECT_NAME} 
    PRIVATE ${LIBSSH_INCLUDE_DIRS}
    PRIVATE ${CMAKE_BINARY_DIR}
)
target_link_libraries(${PROJECT_NAME} 
    PRIVATE ${LIBSSH_LIBRARIES}
)
#set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${HEADERS}")

install(
    TARGETS ${PROJECT_NAME} 
    LIBRARY DESTINATION /usr/lib
    
)
install(DIRECTORY include/bone DESTINATION include)

