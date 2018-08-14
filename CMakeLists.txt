cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(linalglib 
    VERSION 0.0.1 
    DESCRIPTION "Library for Linear Algebra" 
    LANGUAGES CXX)

set(TARGET_NAME ${PROJECT_NAME})
 
add_subdirectory(lib)
add_subdirectory(main)