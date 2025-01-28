cmake_minimum_required(VERSION 3.30)
project(QC_Sim)

# set c++
set(CMAKE_TOOLCHAIN_FILE "/Users/paraspokharel/Programming/QC-Sim/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "" FORCE)
set(CMAKE_CXX_STANDARD 20)

# target define
set(SOURCES
    src/main.cpp
    src/QuantumState.cpp
    src/QuantumCircuit.cpp
)

add_executable(QC_Sim ${SOURCES})

# target header files
target_include_directories(QC_Sim PRIVATE include)

# links to target
find_package(Eigen3 CONFIG REQUIRED)
target_link_libraries(QC_Sim PRIVATE Eigen3::Eigen)
