cmake_minimum_required(VERSION 3.10)
project(touch_ssh)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Найдите библиотеку Libssh с помощью pkg-config
include(FindPkgConfig)
pkg_check_modules(LIBSSH REQUIRED libssh)

# Добавьте исходные файлы вашего проекта
add_executable(${PROJECT_NAME} src/main.cpp)

# Укажите зависимости вашего проекта от Libssh
target_include_directories(${PROJECT_NAME} PRIVATE ${LIBSSH_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBSSH_LIBRARIES})
