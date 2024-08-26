set(
    HEADER_PATH
    "${BONE_SOURCE_DIR}/include/bone"
)
set(
    HEADER
    HEADER_PATH/calagen.hpp
    HEADER_PATH/config.hpp
)
set(
    SOURCE 
    calagen.cpp
)

configure_file("config.hpp.in" "${CMAKE_CURRENT_BINARY_DIR}/config_impl.hpp")

add_library(
    ${PROJECT_NAME}
    ${HEADER}
    ${SOURCE}
)
target_include_directories(${PROJECT_NAME} 
    PUBLIC
    $<BUILD_INTERFACE:${MY_LIBRARY_SOURCE_DIR}/include> # for headers when building
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}> # for config_impl.hpp when building
    $<INSTALL_INTERFACE:${include_dest}> # for client in install mode
    # $<INSTALL_INTERFACE:${lib_dest}> # for config_impl.hpp in install mode)
) 

install(TARGETS my_library DESTINATION "${main_lib_dest}")
install(FILES ${header} DESTINATION "${include_dest}")
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/config_impl.hpp DESTINATION "${include_dest}")
