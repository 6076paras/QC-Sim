cmake_minimum_required(VERSION 3.30)
project(QC_Sim)
set(CMAKE_TOOLCHAIN_FILE "/Users/paraspokharel/Programming/QC-Sim/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "" FORCE)
set(CMAKE_CXX_STANDARD 20)

add_executable(QC_Sim main.cpp)
find_package(Eigen3 CONFIG REQUIRED)
target_link_libraries(QC_Sim PRIVATE Eigen3::Eigen)
