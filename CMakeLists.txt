cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled main.cpp)
target_link_libraries(untitled /Users/bytedance/sdk/glfw-3.3.8/lib-arm64/libglfw.3.dylib)
target_include_directories(untitled PUBLIC /Users/bytedance/sdk/glfw-3.3.8/include)

target_link_libraries(untitled /Users/bytedance/sdk/glew-2.2.0/build/lib/libGLEW.2.2.0.dylib)
target_link_libraries(untitled /Users/bytedance/sdk/glew-2.2.0/build/lib/libGLEW.2.2.dylib)
target_link_libraries(untitled /Users/bytedance/sdk/glew-2.2.0/build/lib/libGLEW.dylib)
target_link_libraries(untitled /Users/bytedance/sdk/glew-2.2.0/build/lib/libGLEW.a)
target_include_directories(untitled PUBLIC /Users/bytedance/sdk/glew-2.2.0/include)

if (APPLE)
    target_link_libraries(untitled "-framework OpenGL")
    target_link_libraries(untitled "-framework GLUT")
endif ()

target_link_libraries(untitled /Users/bytedance/sdk/soil/lib/libSOIL.a)
target_include_directories(untitled PUBLIC /Users/bytedance/sdk/soil/src)

# mac cocoa 引入
find_library(COCOA Cocoa)
target_link_libraries(untitled ${COCOA})

target_include_directories(untitled PUBLIC /Users/bytedance/sdk/glm/)