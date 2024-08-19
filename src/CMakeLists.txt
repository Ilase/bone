set(header_path 
    "${SOURCE_DIR}/include/bone"
)
set(header 
    "${header_path}/calagen.hpp"
)
set(src
    calagen.hpp
)


#Configure
#configure_file()

add_library(${PROJECT_NAME} ${header} ${src})
target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${BONE_SOURCE_DIR}/include> # for headers when building
	$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}> # for config_impl.hpp when building
    $<INSTALL_INTERFACE:${include_dest}> # for client in install mode
    #$<INSTALL_INTERFACE:${lib_dest}> # for config_impl.hpp in install mode
)

install(TARGETS ${PROJECT_NAME} DESTINATION "${main_lib_dest}")
install(FILES ${header} DESTINATION "${include_dest}")
#install(FILES ${CMAKE_CURRENT_BINARY_DIR}/config_impl.hpp DESTINATION "${include_dest}")
