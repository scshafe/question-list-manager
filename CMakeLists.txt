cmake_minimum_required(VERSION 3.15)

include(CMakePrintHelpers)

set(CMAKE_TOOLCHAIN_FILE "bbb-deb-11-hello.cmake")

project(question-manager VERSION 1.0)
# project(question-manager CXX)

# find_package(JSONCPP REQUIRED)

# add_executable(DESKTOP-QUESTION-MANAGER src/view/desktop-app/main.cpp)
# add_executable(EMBEDDED-QUESTION-MANAGER ...)






# add_library(QUESTION-API src/model/question-api/question-manager.cpp src/model/question-api/question.cpp src/model/question-api/json-qm.cpp)
# # target_link_libraries(${PROJECT_NAME} JsonCpp::JsonCpp)
# find_package(jsoncpp REQUIRED)
# target_link_libraries(QUESTION-API ${jsoncpp_LIBRARIES})
# target_include_directories(QUESTION-API PUBLIC ${jsoncpp_INCLUDE_DIRS} src/model/question-api)


# add_executable(DESKTOP-CONTROLLER src/controller/desktop-controller/main.cpp)
# target_link_libraries(DESKTOP-CONTROLLER PUBLIC QUESTION-API)
# target_include_directories(DESKTOP-CONTROLLER PUBLIC src/model/question-api)


find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0)

add_executable(EMBEDDED-GUI src/view/embedded-app/opengtk-version/start-gui.cpp
                            src/view/embedded-app/opengtk-version/main-window.cpp
                            src/view/embedded-app/opengtk-version/question-card.cpp)


target_include_directories(EMBEDDED-GUI PRIVATE ${GTKMM_INCLUDE_DIRS}  )

# cmake_print_variables(GTKMM_LIBRARY_DIRS)
target_link_directories(EMBEDDED-GUI PRIVATE ${GTKMM_LIBRARY_DIRS}  )


# cmake_print_variables(GTKMM_INCLUDE_DIRS)


target_link_libraries(EMBEDDED-GUI ${GTKMM_LIBRARIES})

