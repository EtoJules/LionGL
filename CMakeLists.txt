cmake_minimum_required(VERSION 3.16)
project(ClGL)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include_directories(src)
include_directories(include)
include_directories(libs)
include_directories(src/Core)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_subdirectory(src)
add_subdirectory(libs/glew-2.1.0/build/cmake)

set(CMAKE_CXX_STANDARD 14)
add_executable(ClGL main.cpp)

target_link_libraries(ClGL ${SDL2_LIBRARIES})
target_link_libraries(ClGL Sources)
target_link_libraries(ClGL glew_s)
