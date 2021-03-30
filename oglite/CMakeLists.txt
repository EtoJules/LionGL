cmake_minimum_required(VERSION 3.16)
project(oglite VERSION 0.1.0)

include(CTest)
enable_testing()
include_directories(src)
include_directories(src/Core)
include_directories(include)

add_subdirectory(src)

if(UNIX)
target_link_libraries(oglite ${CMAKE_CURRENT_SOURCE_DIR}/bin/glew/linux/libGLEWd.a)
endif(UNIX)

if(WIN32)
target_link_libraries(oglite ${CMAKE_CURRENT_SOURCE_DIR}/bin/glew/windows/glew32.lib)
endif(WIN32)