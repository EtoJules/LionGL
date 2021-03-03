cmake_minimum_required(VERSION 3.16)
#vcpkg
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
CACHE STRING "Vcpkg toolchain file")
project(ClGL)

include_directories(src)
include_directories(libs)
include_directories(includes)
include_directories(src/Core)

find_package(SDL2 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_path(STB_INCLUDE_DIRS "stb.h")

add_subdirectory(src)
add_subdirectory(libs)

set(CMAKE_CXX_STANDARD 14)
add_executable(ClGL main.cpp)

target_link_libraries(ClGL SandboxExamples)
target_link_libraries(ClGL Core)
target_link_libraries(ClGL Sources)

target_link_libraries(ClGL SDL2::SDL2main SDL2::SDL2-static)
target_link_libraries(ClGL libs)
target_include_directories(ClGL PRIVATE ${STB_INCLUDE_DIRS})
target_link_libraries(ClGL GLEW::GLEW)
