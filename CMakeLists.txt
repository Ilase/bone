cmake_minimum_required(VERSION 3.14)
project(
    bone
)

set(BONE_VERSION_MAJOR 1 CACHE STRING "major version" FORCE)
set(BONE_VERSION_MINOR 0 CACHE STRING "minor version" FORCE)
set(BONE_VERSION ${MY_LIBRARY_VERSION_MAJOR}.${MY_LIBRARY_VERSION_MINOR} CACHE STRING "version" FORCE)
# set(tool_dest "bin")
set(BONE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(include_dest "include/bone-${MY_LIBRARY_VERSION}")
set(main_lib_dest "lib/bone-${MY_LIBRARY_VERSION}")
set(lib_dest "${main_lib_dest}/${CMAKE_BUILD_TYPE}")

option(BONE_USE_FANCY_NEW_CLASS "whether or not to use fancy new class" ON)
option(BONE_DEBUG_MODE "whether or not debug mode is activated" OFF)

include(FindPkgConfig)
pkg_check_modules(LIBSSH REQUIRED libssh)

