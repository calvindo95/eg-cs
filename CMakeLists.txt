cmake_minimum_required(VERSION 3.6)

# The project name
project(EventServer)
set(CLIENT "egc")
set(SERVER "egs")

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_subdirectory(source)