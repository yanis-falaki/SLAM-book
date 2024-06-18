cmake_minimum_required(VERSION 3.16)
project(Chapter3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (APPLE)
    set(DIRECTORY_PREFIX "/usr/local/")
elseif (UNIX)
    set(DIRECTORY_PREFIX "/usr/")
endif()

find_package(Sophus REQUIRED)

# Eigen
include_directories(${DIRECTORY_PREFIX}include/eigen3)
add_executable(useSophus useSophus.cpp)
target_link_libraries(useSophus Sophus::Sophus)
