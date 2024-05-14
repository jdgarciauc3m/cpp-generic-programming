cmake_minimum_required(VERSION 3.27)
project(max)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors -Wsign-conversion)

set(CMAKE_CXX_CLANG_TIDY clang-tidy -header-filter=.*)

add_executable(main01 main01.cpp)
add_executable(main02 main02.cpp)
add_executable(main03 main03.cpp)
add_executable(main04 main4.cpp)
add_executable(main05 main05.cpp)