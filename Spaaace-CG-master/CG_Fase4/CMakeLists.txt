cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -o3 -g -l GLEW")



project(engine)
set(ENGINE_FILES ./Engine/engine.cpp ./Engine/shape.cpp ./tinyxml2.cpp Generator/point.cpp Engine/action.cpp Engine/action.h Engine/parser.cpp Engine/parser.h Engine/group.cpp Engine/group.h Engine/light.cpp Engine/light.h Engine/material.cpp Engine/material.h)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(DevIL REQUIRED)
link_libraries(${IL_LIBRARIES} )
include_directories(${IL_INCLUDE_DIR})

add_executable(engine ${ENGINE_FILES})
target_link_libraries(engine ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${IL_LIBRARIES})

project(generator)
set(GENERATOR_FILES ./Generator/generator.cpp ./Generator/box.cpp ./Generator/cone.cpp
                   ./Generator/plane.cpp ./Generator/sphere.cpp Generator/point.cpp Generator/torus.cpp Generator/torus.h)

add_executable(generator ${GENERATOR_FILES})
