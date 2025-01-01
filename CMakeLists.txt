cmake_minimum_required(VERSION 3.30)
project(QC_Sim)

# set c++
set(CMAKE_TOOLCHAIN_FILE "/Users/paraspokharel/Programming/QC-Sim/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "" FORCE)
set(CMAKE_CXX_STANDARD 20)

# target define
add_executable(QC_Sim src/main.cpp)

# collect class source files (excluding main.cpp)
file(GLOB_RECURSE CLASS_SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)
list(FILTER CLASS_SOURCES EXCLUDE REGEX ".*main\\.cpp$")

# add the class sources to the target separately
target_sources(${PROJECT_NAME}
    PRIVATE
        ${CLASS_SOURCES}
)

# target header files
target_include_directories(QC_Sim PRIVATE include)

# links to target
find_package(Eigen3 CONFIG REQUIRED)
target_link_libraries(QC_Sim PRIVATE Eigen3::Eigen)
