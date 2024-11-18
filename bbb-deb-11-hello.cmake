# This project runs on the Debian Linux BBB console image
set(CMAKE_SYSTEM_NAME Linux)
 
# These are the cross-compilers installed with Debian's package
set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc CACHE FILEPATH "C compiler path")
set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++ CACHE FILEPATH "C++ compiler path")
 
# Use the cross compiler package and the target environment as root paths
set(ReferenceFilesystem "/home/cole/Documents/bbb-11-reference-filesystem/rootfs")
set(CMAKE_FIND_ROOT_PATH "/usr/arm-linux-gnueabihf")
set(CMAKE_SYSROOT "${ReferenceFilesystem}")

set(ENV{PKG_CONFIG_DIR} "")
# set(ENV{PKG_CONFIG_LIBDIR} "${CMAKE_SYSROOT}/usr/lib/pkgconfig:${CMAKE_SYSROOT}/usr/share/pkgconfig")
set(ENV{PKG_CONFIG_LIBDIR} "${CMAKE_SYSROOT}/usr/lib/arm-linux-gnueabihf/pkgconfig:${CMAKE_SYSROOT}/usr/share/pkgconfig")
set(ENV{PKG_CONFIG_SYSROOT_DIR} ${CMAKE_SYSROOT})

# set(PKG_CONFIG_EXECUTABLE "/somewhere/bin/aarch64-unknown-linux-gnueabi-pkg-config" CACHE FILEPATH "pkg-config executable")
 
# Adjust the default behavior of the FIND_XXX() commands:
# Search build host for:
#    - Programs
# Search reference filesystem for:
#    - headers, libraries, and packages
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
 
# The headers returned from find_package() are not prefixed by the system root 
# of the cross compile. This function will iterate each and prefix the sysroot
# so that the build tools can locate them from the build host.
function(prefix_sysroot_includes found_include_dirs)
    set(replace_include_dirs "")
    foreach(include_dir ${${found_include_dirs}})
        list(APPEND replace_include_dirs "${ReferenceFilesystem}${include_dir}")
    endforeach()
    set(${found_include_dirs} "${replace_include_dirs}" PARENT_SCOPE)
endfunction()
