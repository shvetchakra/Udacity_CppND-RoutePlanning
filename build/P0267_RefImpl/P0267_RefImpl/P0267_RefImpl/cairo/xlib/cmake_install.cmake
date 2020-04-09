# Install script for directory: /mnt/c/Users/chakra/Documents/GitHub/CppND-Route-Planning-Project/P0267_RefImpl/P0267_RefImpl/P0267_RefImpl/cairo/xlib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/mnt/c/Users/chakra/Documents/GitHub/CppND-Route-Planning-Project/lib/libio2d_cairo_xlib.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/mnt/c/Users/chakra/Documents/GitHub/CppND-Route-Planning-Project/P0267_RefImpl/P0267_RefImpl/P0267_RefImpl/cairo/xlib/io2d.h"
    "/mnt/c/Users/chakra/Documents/GitHub/CppND-Route-Planning-Project/P0267_RefImpl/P0267_RefImpl/P0267_RefImpl/cairo/xlib/io2d_cairo_xlib.h"
    "/mnt/c/Users/chakra/Documents/GitHub/CppND-Route-Planning-Project/P0267_RefImpl/P0267_RefImpl/P0267_RefImpl/cairo/xlib/xio2d_cairo_xlib_main.h"
    "/mnt/c/Users/chakra/Documents/GitHub/CppND-Route-Planning-Project/P0267_RefImpl/P0267_RefImpl/P0267_RefImpl/cairo/xlib/xio2d_cairo_xlib_output_surfaces.h"
    "/mnt/c/Users/chakra/Documents/GitHub/CppND-Route-Planning-Project/P0267_RefImpl/P0267_RefImpl/P0267_RefImpl/cairo/xlib/xio2d_cairo_xlib_surfaces.h"
    "/mnt/c/Users/chakra/Documents/GitHub/CppND-Route-Planning-Project/P0267_RefImpl/P0267_RefImpl/P0267_RefImpl/cairo/xlib/xio2d_cairo_xlib_surfaces_impl.h"
    "/mnt/c/Users/chakra/Documents/GitHub/CppND-Route-Planning-Project/P0267_RefImpl/P0267_RefImpl/P0267_RefImpl/cairo/xlib/xio2d_cairo_xlib_unmanaged_output_surfaces.h"
    )
endif()

