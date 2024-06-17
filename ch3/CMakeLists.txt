project(Chapter3)
add_executable(useGeometry useGeometry/useGeometry.cpp)
add_executable(useEigen useEigen/eigenMatrix.cpp)
add_executable(coordinateTransform examples/coordinateTransform.cpp)
# Add header file

if (APPLE)
    set(DIRECTORY_PREFIX "/usr/local/")
ELSEIF(UNIX)
    set(DIRECTORY_PREFIX "/usr/")
endif()

include_directories(${DIRECTORY_PREFIX}include/eigen3)