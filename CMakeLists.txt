cmake_minimum_required(VERSION 3.16)
project(ClGL)

include_directories(src)
include_directories(includes)
include_directories(src/Core)

link_directories(${CMAKE_BINARY_DIR}/bin/*/)
find_package(OpenGL REQUIRED)

add_subdirectory(src)
add_subdirectory(includes)
set(CMAKE_CXX_STANDARD 14)
add_executable(ClGL main.cpp)

target_link_libraries(ClGL SandboxExamples)
target_link_libraries(ClGL Core)
target_link_libraries(ClGL Sources)

if(UNIX)
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/bin/assimp/linux/libassimp.so)
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/bin/SDL2/linux/libSDL2-2.0.so)
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/bin/glew/linux/libGLEWd.a)
endif(UNIX)

if(WIN32)
target_link_libraries(ClGL ${CMAKE_CURRENT  _SOURCE_DIR}/bin/assimp/windows/assimp-vc142-mt.lib)
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/bin/SDL2/windows/SDL2.lib)
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/bin/glew/windows/glew32.lib)
endif(WIN32)

target_link_libraries(ClGL imGUI)
target_link_libraries(ClGL OpenGL::GL)

include(CPack)