cmake_minimum_required(VERSION 3.16)
project(fnr-slam LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Threads REQUIRED)
find_package(CUDA REQUIRED)
find_package(OpenMP)
if(OPENMP_FOUND)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OPENMP_CXX_FLAGS}")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OPENMP_EXE_LINKER_FLAGS}")
endif()

set(HEADERS include)
include_directories(${HEADERS} ${OpenCV_INCLUDE_DIRS} ${Eigen3_INCLUDE_DIRS} ${Threads_INCLUDE_DIRS} ${CUDA_INCLUDE_DIRS})
set(SOURCES
	src/FNRSLAM.cpp
	src/VideoStream.cpp
	src/data_structures/Graph.cpp
	src/data_structures/Node.cpp
)

add_library(fnr_slam SHARED ${SOURCES})
target_link_libraries(fnr_slam ${OpenCV_LIBS} ${Eigen3_LIBS} ${Threads_LIBS} ${CUDA_LIBS})
