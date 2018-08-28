set(LIB_HEADER_PATH ${CMAKE_SOURCE_DIR}/lib/include)
include_directories(${LIB_HEADER_PATH})

include_directories(${CMAKE_SOURCE_DIR}/gtest)

set(TEST_HEADER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(TEST_SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/source)

#set(TEST_HEADER_FILES
#   ${TEST_HEADER_PATH}/foo.hpp
#   ${TEST_HEADER_PATH}/bar.hpp)
#include_directories(${TEST_HEADER_FILES}) # not sure if necessary

set(TEST_SOURCE_FILES
    ${TEST_SOURCE_PATH}/main.cpp)

add_executable(test_linalg ${TEST_SOURCE_FILES})

target_link_libraries(test_linalg linalg)
target_link_libraries(test_linalg gtest_main)