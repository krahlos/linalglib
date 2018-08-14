set(LIB_HEADER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(LIB_SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/source)

set(LIB_HEADER_FILES
    ${LIB_HEADER_PATH}/cmatrix.hpp
    ${LIB_HEADER_PATH}/cvector.hpp)

set(LIB_SOURCE_FILES
    ${LIB_SOURCE_PATH}/cmatrix.cpp
    ${LIB_SOURCE_PATH}/cvector.cpp)

add_library(LinAlg ${LIB_HEADER_FILES} ${LIB_SOURCE_FILES})

target_compile_options(LinAlg PRIVATE -Werror)