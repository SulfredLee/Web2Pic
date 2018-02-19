cmake_minimum_required (VERSION 2.8.12)

# Maps to a solution filed (*.sln). The solution will
# have all targets (exe, lib, dll) as projects (.vcproj)
project(Web2Pic)

# Turn on the ability to create folders to organize projects (.vcproj)
# It creates "CMakePredefinedTargets" folder by default and adds CMake
# defined projects like INSTALL.vcproj and ZERO_CHECK.vcproj
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Command to output information to the console
# Useful for displaying errors, warnings, and debugging
set(CMAKE_CXX_FLAGS "-Wall -fPIC -std=c++14")
message(STATUS "Root - cxx Flags: " ${CMAKE_CXX_FLAGS})

# Handle Preprocess Flags
if (UNIX)
  add_definitions(-DUNIX)
else ()
  add_definitions(-DWINDOWS -DWIN32 "/EHsc")
endif ()


# Handle QT libaries
if (UNIX)
  set(QT_ROOT "/usr/local/Qt/5.6.2/5.6/gcc_64/")
else ()
  set(QT_ROOT "C:\\Qt\\Qt5.6.2\\5.6\\msvc2013_64\\")
endif ()
set(QT_INCLUDE_DIR "${QT_ROOT}include")
set(QT_LIBRARY_DIR "${QT_ROOT}lib")
set(CMAKE_PREFIX_PATH ${QT_ROOT})

# Sub-directories where more CMakeLists.txt exist
add_subdirectory(Web2Pic/FrontEnd)
add_subdirectory(Web2Pic)
