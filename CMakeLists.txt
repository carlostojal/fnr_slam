cmake_minimum_required(VERSION 3.16)
project(fnr-slam LANGUAGES CXX VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Threads REQUIRED)

set(HEADERS include)
include_directories(${HEADERS} ${OpenCV_INCLUDE_DIRS} ${Eigen3_INCLUDE_DIRS} ${Threads_INCLUDE_DIRS})
set(SOURCES
	src/FNRSLAM.cpp
	src/VideoStream.cpp
	src/data_structures/Graph.cpp
	src/data_structures/Node.cpp
)

add_library(fnr_slam SHARED ${SOURCES})
target_link_libraries(fnr_slam ${OpenCV_LIBS} ${Eigen3_LIBS} ${Threads_LIBS})
