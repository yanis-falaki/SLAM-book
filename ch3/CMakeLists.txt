cmake_minimum_required(VERSION 3.16)
message(STATUS "C compiler: ${CMAKE_C_COMPILER}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER}")
project(Chapter3)
add_executable(useGeometry useGeometry/useGeometry.cpp)
add_executable(useEigen useEigen/eigenMatrix.cpp)
add_executable(coordinateTransform examples/coordinateTransform.cpp)
add_executable(plotTrajectory examples/plotTrajectory.cpp)

if (APPLE)
    set(DIRECTORY_PREFIX "/usr/local/")
ELSEIF(UNIX)
    set(DIRECTORY_PREFIX "/usr/")
endif()

find_package(Pangolin)
include_directories( ${Pangolin_INCLUDE_DIRS} )
target_link_libraries(plotTrajectory ${Pangolin_LIBRARIES})

# Add header file
include_directories(${DIRECTORY_PREFIX}include/eigen3)