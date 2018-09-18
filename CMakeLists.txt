cmake_minimum_required(VERSION 3.9)

include(FindPkgConfig)

project(EventStore)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE HEADERS "include/*.h*")
file(GLOB_RECURSE SOURCES "src/*.c*")

add_executable(event_store ${SOURCES} ${HEADERS})
