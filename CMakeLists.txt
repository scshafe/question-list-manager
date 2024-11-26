cmake_minimum_required(VERSION 3.15)

include(CMakePrintHelpers)

set(CMAKE_TOOLCHAIN_FILE "bbb-deb-11-hello.cmake")

project(question-manager VERSION 1.0)

set(GUI_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src/view/embedded-app/opengtk-version") # 


cmake_print_variables(CMAKE_SOURCE_DIR)
cmake_print_variables(GUI_SOURCE_DIR)



find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0)

pkg_check_modules(GWEATHER gweather-3.0)

pkg_check_modules(LIBCURL libcurl)

pkg_check_modules(JSONCPP jsoncpp)

add_executable(EMBEDDED-GUI ${GUI_SOURCE_DIR}/start-gui.cpp
                            ${GUI_SOURCE_DIR}/main-window.cpp
                            ${GUI_SOURCE_DIR}/question-card.cpp
                            ${GUI_SOURCE_DIR}/header.cpp
                            ${GUI_SOURCE_DIR}/time-widget.cpp
                            ${GUI_SOURCE_DIR}/temp-widget.cpp
                            ${GUI_SOURCE_DIR}/time-helper.cpp)


target_include_directories(EMBEDDED-GUI PRIVATE ${GTKMM_INCLUDE_DIRS} ${GWEATHER_INCLUDE_DIRS} ${LIBCURL_INCLUDE_DIRS} ${JSONCPP_INCLUDE_DIRS})

# cmake_print_variables(GTKMM_LIBRARY_DIRS)
target_link_directories(EMBEDDED-GUI PRIVATE ${GTKMM_LIBRARY_DIRS} ${GWEATHER_LIBRARY_DIRS} ${LIBCURL_LIBRARY_DIRS} ${JSONCPP_LIBRARY_DIRS})


# cmake_print_variables(GTKMM_INCLUDE_DIRS)


target_link_libraries(EMBEDDED-GUI ${GTKMM_LIBRARIES} ${GWEATHER_LIBRARIES} ${LIBCURL_LIBRARIES} ${JSONCPP_LIBRARIES})

