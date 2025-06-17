cmake_minimum_required(VERSION 3.10.0)
project(MillenniumEngine VERSION 0.1.0 LANGUAGES C CXX)
find_package(assimp REQUIRED)



file(GLOB IAMGUI_SRC
    "include/imgui/*.cpp"
    "include/imgui/imgui_impl_glfw.cpp"
    "include/imgui/imgui_impl_opengl3.cpp")

add_executable(MillenniumEngine src/main.cpp 
                                src/terrarian.cpp
                                src/model.cpp 
                                src/mesh.cpp 
                                src/camera.cpp 
                                src/stb_image.cpp 
                                src/tranformation.cpp 
                                src/texture.cpp 
                                src/ebo.cpp 
                                src/render.cpp 
                                src/vao.cpp 
                                src/vbo.cpp 
                                src/window.cpp 
                                src/core.cpp 
                                src/shader.cpp 
                                src/glad.c
                                ${IAMGUI_SRC})


target_include_directories(MillenniumEngine PRIVATE include)
target_link_libraries(MillenniumEngine glfw GL assimp)