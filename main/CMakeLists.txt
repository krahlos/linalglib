set(LIB_HEADER_PATH ${CMAKE_SOURCE_DIR}/lib/include) # or CMAKE_BINARY_DIR? or CMAKE_CURRENT_BINARY_DIR?
include_directories(${LIB_HEADER_PATH})

set(MAIN_HEADER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(MAIN_SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/source)

#set(MAIN_HEADER_FILES
#   ${MAIN_HEADER_PATH}/foo.hpp
#   ${MAIN_HEADER_PATH}/bar.hpp)
#include_directories(${MAIN_HEADER_FILES}) # not sure if necessary

set(MAIN_SOURCE_FILES
    ${MAIN_SOURCE_PATH}/main.cpp)

add_executable(main ${MAIN_SOURCE_FILES})

target_link_libraries(main LinAlg)