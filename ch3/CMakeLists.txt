project(Chapter3)
add_executable(useGeometry useGeometry/useGeometry.cpp)
add_executable(useEigen useEigen/eigenMatrix.cpp)
add_executable(coordinateTransform examples/coordinateTransform.cpp)
# Add header file
include_directories("/usr/local/include/eigen3")