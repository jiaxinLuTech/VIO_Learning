cmake_minimum_required(VERSION 2.8)
project("eigen")
find_package(Eigen3 REQUIRED)
include_directories(
${PROJECT_SOURCE_DIR}/thirdparty/Sophus
${EIGEN3_INCLUDE_DIR})
add_executable(eigen main.cpp )
