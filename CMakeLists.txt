cmake_minimum_required(VERSION 3.19)
project(cses LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE all src/ss/*cpp)

foreach(path ${all})
 get_filename_component(name ${path} NAME_WLE)
 add_executable(${name} ${path})
endforeach()