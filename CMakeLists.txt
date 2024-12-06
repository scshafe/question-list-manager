cmake_minimum_required(VERSION 3.18)
include(CMakePrintHelpers)

set(CMAKE_TOOLCHAIN_FILE "bbb-deb-11-hello.cmake")
project(question-manager VERSION 1.0)


find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)
pkg_check_modules(GWEATHER gweather-3.0)
pkg_check_modules(LIBCURL libcurl)
pkg_check_modules(JSONCPP jsoncpp)

add_executable(EMBEDDED-GUI main.cpp)


add_subdirectory(src/libs)
add_subdirectory(src/controller)
add_subdirectory(src/model)
add_subdirectory(src/view)

target_link_libraries(EMBEDDED-GUI libs)
target_link_libraries(EMBEDDED-GUI controller)
target_link_libraries(EMBEDDED-GUI model)
target_link_libraries(EMBEDDED-GUI view)


target_include_directories(EMBEDDED-GUI PRIVATE ${GTKMM_INCLUDE_DIRS} ${GWEATHER_INCLUDE_DIRS} ${LIBCURL_INCLUDE_DIRS} ${JSONCPP_INCLUDE_DIRS} "${CMAKE_SYSROOT}/home/debian/boost_1_82_0")

# cmake_print_variables(GTKMM_LIBRARY_DIRS)
target_link_directories(EMBEDDED-GUI PRIVATE ${GTKMM_LIBRARY_DIRS} ${GWEATHER_LIBRARY_DIRS} ${LIBCURL_LIBRARY_DIRS} ${JSONCPP_LIBRARY_DIRS} "${CMAKE_SYSROOT}/home/debian/boost_1_82_0/stage/lib")


# cmake_print_variables(GTKMM_INCLUDE_DIRS)
target_link_libraries(EMBEDDED-GUI ${GTKMM_LIBRARIES} ${GWEATHER_LIBRARIES} ${LIBCURL_LIBRARIES} ${JSONCPP_LIBRARIES} "boost_program_options")

