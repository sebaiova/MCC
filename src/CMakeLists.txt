# CMakeList.txt : CMake project for MCC, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Add source to this project's executable.
add_executable (MCC "main.cpp")

# TODO: Add tests and install targets if needed.