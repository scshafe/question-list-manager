cmake_minimum_required(VERSION 3.18)

include(CMakePrintHelpers)

set(CMAKE_TOOLCHAIN_FILE "bbb-deb-11-hello.cmake")

project(question-manager VERSION 1.0)

# include(src/controller/CMakeLists.txt)
# include(src/model/CMakeLists.txt)
# include(src/view/CMakeLists.txt)

# set(VIEW_SOURCES "${CMAKE_SOURCE_DIR}/src/view") # 
# set(VIEW_HEADERS "${CMAKE_SOURCE_DIR}/src/view/include")

# set(MODEL_SOURCES "${CMAKE_SOURCE_DIR}/src/model") # 
# set(MODEL_HEADERS "${CMAKE_SOURCE_DIR}/src/model/include")

# set(CONTROL_SOURCES "${CMAKE_SOURCE_DIR}/src/controller") # 
# set(CONTROL_HEADERS "${CMAKE_SOURCE_DIR}/src/controller/include")

# cmake_print_variables(CMAKE_SOURCE_DIR)
# cmake_print_variables(VIEW_SOURCES)



find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0)
pkg_check_modules(GWEATHER gweather-3.0)
pkg_check_modules(LIBCURL libcurl)
pkg_check_modules(JSONCPP jsoncpp)

add_executable(EMBEDDED-GUI main.cpp)
                            # ${VIEW_SOURCES}/main-window.cpp
                            # ${VIEW_SOURCES}/question-card.cpp
                            # ${VIEW_SOURCES}/header.cpp
                            # ${VIEW_SOURCES}/time-widget.cpp
                            # ${VIEW_SOURCES}/temp-widget.cpp
                            # ${VIEW_SOURCES}/time-helper.cpp)

# foreach(dir IN ITEMS src/controller src/view)
#   add_subdirectory(${CMAKE_SOURCE_DIR}/${dir} ${dir}/)
#   target_link_libraries(${PROJECT_NAME} ${dir}_lib)
#   add_dependencies(${PROJECT_NAME} ${dir}_lib)
# endforeach()

add_subdirectory(src/libs)
add_subdirectory(src/controller)

add_subdirectory(src/model)
add_subdirectory(src/view)



target_link_libraries(EMBEDDED-GUI libs)
target_link_libraries(EMBEDDED-GUI controller)

target_link_libraries(EMBEDDED-GUI model)
target_link_libraries(EMBEDDED-GUI view)


target_include_directories(EMBEDDED-GUI PRIVATE ${GTKMM_INCLUDE_DIRS} ${GWEATHER_INCLUDE_DIRS} ${LIBCURL_INCLUDE_DIRS} ${JSONCPP_INCLUDE_DIRS})

# cmake_print_variables(GTKMM_LIBRARY_DIRS)
target_link_directories(EMBEDDED-GUI PRIVATE ${GTKMM_LIBRARY_DIRS} ${GWEATHER_LIBRARY_DIRS} ${LIBCURL_LIBRARY_DIRS} ${JSONCPP_LIBRARY_DIRS})


# cmake_print_variables(GTKMM_INCLUDE_DIRS)


target_link_libraries(EMBEDDED-GUI ${GTKMM_LIBRARIES} ${GWEATHER_LIBRARIES} ${LIBCURL_LIBRARIES} ${JSONCPP_LIBRARIES})

