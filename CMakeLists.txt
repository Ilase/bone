#==================================================
#Define version
cmake_minimum_required(VERSION 3.11)
project(
    bone
    VERSION 1.0.0
)
#==================================================
#Deploy version of library 
#Setters
set(BONE_LIBRARY_VERISION_MAJOR 1 CACHE STRING "major version" FORCE)
set(BONE_LIBRARY_VERISION_MINOR 0 CACHE STRING "minor version" FORCE)
set(BONE_VERSION ${BONE_LIBRARY_VERISION_MAJOR}.${BONE_LIBRARY_VERISION_MINOR} CACHE STRING "version" FORCE)
set(BONE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(tool_dest "bin")
set(include_dest "include/bone-${BONE_VERSION}")
set(main_lib_dest "lib/bone-${BONE_VERSION}")
set(lib_dest ${main_lib_dest}/${CMAKE_BUILD_TYPE})
# set(LIBSSH_INCLUDE_DIR "/usr/include/libssh")
# set(LIBSSH_LIBRARIES "/usr/lib/x86_64-linux-gnu/libssh.a" )

#==================================================
option(BONE_USE_FANCY_NEW_CLASS "fancy class disabeled" ON)
option(BONE_USE_DEBUG_MODE "dwbug mode disabeled" OFF)
#==================================================
#Subdirectories without include
add_subdirectory(src)
#add_subdirectory(example)
#add_subdirectory()
#==================================================

#==================================================
#Define library target
# include(FindPkgConfig)
# pkg_check_modules(libSSH REQUIRED libssh)
#==================================================


target_include_directories(${PROJECT_NAME} 
    PRIVATE ${LIBSSH_INCLUDE_DIRS}
    PUBLIC ${SOURCE_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR}
)
#==================================================
# get_filename_component(SELF_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
# include(${SELF_DIR}/${CMAKE_BUILD_TYPE}bone-config.cmake)
# install(FILES bone-config.cmake DESTINATION ${main_lib_dest})
# install(EXPORT bone DESTINATION ${main_lib_dest})
#==================================================





#set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${HEADERS}")

# install(
#     TARGETS ${PROJECT_NAME} 
#     LIBRARY DESTINATION /usr/lib
    
# )
# install(DIRECTORY include/bone DESTINATION include)

