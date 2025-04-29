

file(GLOB view_sources *.cpp)
# target_sources(EMBEDDED-GUI PRIVATE ${view_sources})

# target_include_directories(EMBEDDED-GUI INTERFACE src/controller)

# add_library(view_lib foo.f90 bar.f90)
# target_link_libraries(view_lib things_source1_links)
# add_dependencies(source1_lib things_source1_uses)

add_library(view STATIC ${view_sources})

target_include_directories(controller PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                             ../controller)

target_include_directories(view 
                           PRIVATE 
                           ${GTKMM_INCLUDE_DIRS} 
                           ${GWEATHER_INCLUDE_DIRS} 
                           ${LIBCURL_INCLUDE_DIRS} 
                           ${JSONCPP_INCLUDE_DIRS} 
                           controller 
                           model
                           libs
                         )

# cmake_print_variables(GTKMM_LIBRARY_DIRS)
target_link_directories(view 
                        PRIVATE 
                        ${GTKMM_LIBRARY_DIRS} 
                        ${GWEATHER_LIBRARY_DIRS} 
                        ${LIBCURL_LIBRARY_DIRS} 
                        ${JSONCPP_LIBRARY_DIRS} 
                        controller
                      )


# cmake_print_variables(GTKMM_INCLUDE_DIRS)


target_link_libraries(view 
                      ${GTKMM_LIBRARIES} 
                      ${GWEATHER_LIBRARIES} 
                      ${LIBCURL_LIBRARIES} 
                      ${JSONCPP_LIBRARIES} 
                      controller
                    )
