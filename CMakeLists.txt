cmake_minimum_required(VERSION 3.16)
project(fnr-slam LANGUAGES CXX)

find_package(OpenCV REQUIRED)
find_package(Threads REQUIRED)

set(target_includes include)
include_directories(${target_includes} ${OpenCV_INCLUDE_DIRS} ${Threads_INCLUDE_DIRS})
set(target_sources
	src/data_structures/Graph.cpp
)

add_library(fnr_slam STATIC ${target_sources})
target_link_libraries(fnr_slam ${OpenCV_LIBS} ${Threads_LIBS})

