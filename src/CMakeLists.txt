set(header_path 
    "${BONE_SOURCE_DIR}/include/bone"
)
set(header 
    "${header_path}/calagen.hpp"
)
set(src
    calagen.cpp
)

#Configure
configure_file("config.hpp.in" "${CMAKE_CURRENT_BINARY_DIR}/config_impl.hpp")


include(FindPkgConfig)
pkg_check_modules(LIBSSH REQUIRED libssh)

#==================================================

add_library(
    ${PROJECT_NAME} 
    ${header} 
    ${src}
)
# get_filename_component(SELF_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
# include(${SELF_DIR}/${CMAKE_BUILD_TYPE}bone.cmake)
# install(FILES bone-config.cmake DESTINATION ${main_lib_dest})
# install(EXPORT ...)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${BONE_SOURCE_DIR}/include> # for headers when building
	$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}> # for config_impl.hpp when building
    $<INSTALL_INTERFACE:${include_dest}> # for client in install mode
    $<INSTALL_INTERFACE:${lib_dest}> # for config_impl.hpp in install mode
    PRIVATE ${LIBSSH_INCLUDE_DIRS} #libssh 
)

install(TARGETS ${PROJECT_NAME} DESTINATION "${main_lib_dest}")
install(FILES ${header} DESTINATION "${include_dest}")
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/config_impl.hpp DESTINATION "${lib_dest}")

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION ${lib_dest})

install(FILES my_library-config.cmake DESTINATION ${main_lib_dest})
install(EXPORT ${PROJECT_NAME} DESTINATION ${lib_dest})

get_filename_component(SELF_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
include(${SELF_DIR}/${CMAKE_BUILD_TYPE}bone.cmake)


# set(asd ${cmake_install_li})