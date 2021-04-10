cmake_minimum_required(VERSION 3.16)
project(ClGL)

#Good includes
include_directories(src)
include_directories(includes)
include_directories(src/Core)
include_directories(../oglite/src/)

find_package(OpenGL REQUIRED)

add_subdirectory(src)
add_subdirectory(includes)

set(CMAKE_CXX_STANDARD 14)
add_executable(ClGL main.cpp)

#Source Code
target_link_libraries(ClGL SandboxExamples)
target_link_libraries(ClGL Core)

#Libraries
target_link_libraries(ClGL imGUI)
target_link_libraries(ClGL OpenGL::GL)
#oglite static lib
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/../oglite/build/src/liboglite.a)

#Platform specific libraries
if(UNIX)
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/bin/linux/libassimp.so)
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/bin/linux/libSDL2-2.0.so)
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/bin/linux/libGLEWd.a)
endif(UNIX)

if(WIN32)
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/bin/windows/assimp-vc142-mt.lib)
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/bin/windows/SDL2.lib)
target_link_libraries(ClGL ${CMAKE_CURRENT_SOURCE_DIR}/bin/windows/glew32.lib)
endif(WIN32)

include(CPack)