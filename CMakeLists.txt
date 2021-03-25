cmake_minimum_required(VERSION 3.16)
#vcpkg
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
CACHE STRING "Vcpkg toolchain file")
project(ClGL)

include_directories(src)
include_directories(libs)
include_directories(includes)
include_directories(src/Core)

link_directories(${CMAKE_BINARY_DIR}/bin/*/)
find_package(GLEW REQUIRED)

add_subdirectory(src)
add_subdirectory(libs)

set(CMAKE_CXX_STANDARD 14)
add_executable(ClGL main.cpp)

target_link_libraries(ClGL SandboxExamples)
target_link_libraries(ClGL Core)
target_link_libraries(ClGL Sources)

if(UNIX)
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/bin/assimp/libassimp.so)
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/bin/SDL2/libSDL2-2.0.so)
endif(UNIX)

target_link_libraries(ClGL libs)
target_link_libraries(ClGL GLEW::GLEW)
