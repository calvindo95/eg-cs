cmake_minimum_required(VERSION 3.6)

# The project name
project(EventServer)
set(CLIENT "egc")
set(SERVER "egs")

set(CMAKE_CXX_STANDARD 17)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_subdirectory(source)