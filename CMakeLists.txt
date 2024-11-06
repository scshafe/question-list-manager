cmake_minimum_required(VERSION 3.13)


# set(CMAKE_TOOLCHAIN_FILE "BBBToolchain.cmake")

# set(CMAKE_SYSROOT "/home/cole/beaglebone/cross-compiler-toolchain/linaro-toolchain/rootfs")

# set(ENV{PKG_CONFIG_DIR} "/home/cole/beaglebone/cross-compiler-toolchain/linaro-toolchain/rootfs/usr/bin")
# # set(ENV{PKG_CONFIG_LIBDIR} "${CMAKE_SYSROOT}/usr/lib/arm-linux-gnueabihf:${CMAKE_SYSROOT}/usr/lib/pkgconfig:${CMAKE_SYSROOT}/usr/share/pkgconfig")
# set(ENV{PKG_CONFIG_LIBDIR} "${CMAKE_SYSROOT}/usr/lib/pkgconfig:${CMAKE_SYSROOT}/usr/share/pkgconfig")
# set(ENV{PKG_CONFIG_SYSROOT_DIR} ${CMAKE_SYSROOT})

# set(ENV{PKG_CONFIG_PATH} "/home/cole/beaglebone/cross-compiler-toolchain/linaro-toolchain/rootfs/usr/lib/arm-linux-gnueabihf/pkgconfig")

project(question-manager CXX)

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

# set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
# set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
# set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# find_package(PkgConfig PATHS "/home/cole/beaglebone/cross-compiler-toolchain/linaro-toolchain/rootfs/usr/bin" NO_DEFAULT_PATH)
find_package(PkgConfig REQUIRED)
# find_package(PkgConfig)

pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

add_executable(EMBEDDED-GUI src/view/embedded-app/opengtk-version/start-gui.cpp
                            src/view/embedded-app/opengtk-version/main-window.cpp
                            src/view/embedded-app/opengtk-version/question-card.cpp)

target_link_libraries(EMBEDDED-GUI PUBLIC ${GTKMM_LIBRARIES})
target_include_directories(EMBEDDED-GUI PUBLIC ${GTKMM_INCLUDE_DIRS})
target_link_directories(EMBEDDED-GUI PUBLIC ${GTKMM_LIBRARY_DIRS})
target_compile_options(EMBEDDED-GUI PUBLIC ${GTKMM_CFLAGS_OTHER})


