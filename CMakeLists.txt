cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

if (APPLE)
    message("OS is macOS, set compiler to GNU instead of Apple Clang")

    # TODO Check if GNU is installed

    set(CMAKE_C_COMPILER "gcc")
    set(CMAKE_CXX_COMPILER "g++")
endif()

project(linalglib 
    VERSION 0.0.1 
    DESCRIPTION "Library for Linear Algebra" 
    LANGUAGES CXX
    ) 

add_subdirectory(googletest)
add_subdirectory(lib)
add_subdirectory(test)