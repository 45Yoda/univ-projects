cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -o3 -g")



project(engine)
set(ENGINE_FILES ./Engine/engine.cpp ./Engine/shape.cpp ./tinyxml2.cpp ./Generator/vertex.cpp Engine/action.cpp Engine/action.h Engine/parser.cpp Engine/parser.h Engine/group.cpp Engine/group.h)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(engine ${ENGINE_FILES})
target_link_libraries(engine ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

project(generator)
set(GENERATOR_FILES ./Generator/generator.cpp ./Generator/box.cpp ./Generator/cone.cpp
                   ./Generator/plane.cpp ./Generator/sphere.cpp ./Generator/vertex.cpp Generator/torus.cpp Generator/torus.h)

add_executable(generator ${GENERATOR_FILES})
