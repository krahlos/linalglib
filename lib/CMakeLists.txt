set(LIB_HEADER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(LIB_SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/source)

set(LIB_HEADER_FILES
    ${LIB_HEADER_PATH}/cmatrix.h
    ${LIB_HEADER_PATH}/cvector.h)

set(LIB_SOURCE_FILES
    ${LIB_SOURCE_PATH}/cmatrix.cpp)

add_library(linalg ${LIB_HEADER_FILES} ${LIB_SOURCE_FILES})

target_include_directories(linalg
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/source
)
 
target_compile_options(linalg PRIVATE -Wall -pedantic -Werror -Wextra)