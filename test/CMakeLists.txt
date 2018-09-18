cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)

include_directories(../include/)

include_directories(../third_party/googletest/googletest/include)
include_directories(../third_party/googletest/googletest)

add_subdirectory(googletest)

file(GLOB_RECURSE SOURCES 
  "./src/*.cc"
  "../src/*.c*"
  )

list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/../src/main.cc)

add_executable(event_store_tests ${SOURCES})
target_link_libraries(event_store_tests
  gtest_main
  gtest
  pthread
  )

