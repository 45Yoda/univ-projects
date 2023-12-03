
C/C++:

General -> Additional Include Directories: Path to $(SolutionDir)\SolutionName\include
Preprocessor: GLEW_STATIC

Linker:

General -> Additional Library Directories: Path to $(SolutionDir)\SolutionName\lib
Input: opengl32.lib;glew32s.lib;glut32.lib;freeglut.lib;assimp.lib;
