cmake_minimum_required(VERSION 3.16)
project(ClGL)

#Good includes
include_directories(Sandbox/src)
include_directories(Sandbox/includes)
include_directories(Sandbox/src/Core)
include_directories(oglite/src/)

find_package(OpenGL REQUIRED)

add_subdirectory(oglite)
add_subdirectory(Sandbox/src)
add_subdirectory(Sandbox/includes)
set(CMAKE_CXX_STANDARD 14)
add_executable(ClGL Sandbox/main.cpp)

#Source Code
target_link_libraries(ClGL SandboxExamples)
target_link_libraries(ClGL Core)

#Libraries
target_link_libraries(ClGL imGUI)
target_link_libraries(ClGL OpenGL::GL)
#oglite static lib
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/oglite/build/src/liboglite.a)

#Platform specific libraries
if(UNIX)
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/bin/assimp/linux/libassimp.so)
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/bin/SDL2/linux/libSDL2-2.0.so)
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/bin/glew/linux/libGLEWd.a)
endif(UNIX)

if(WIN32)
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/bin/assimp/windows/assimp-vc142-mt.lib)
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/bin/SDL2/windows/SDL2.lib)
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/bin/glew/windows/glew32.lib)
endif(WIN32)

include(CPack)