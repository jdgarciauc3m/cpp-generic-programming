cmake_minimum_required(VERSION 3.28)
project(record)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors -Wsign-conversion)

include(FetchContent)
FetchContent_Declare(GSL
        GIT_REPOSITORY "https://github.com/microsoft/GSL"
        GIT_TAG "v4.0.0"
        GIT_SHALLOW ON
)
FetchContent_MakeAvailable(GSL)

set(CMAKE_CXX_CLANG_TIDY clang-tidy -header-filter=.*)

add_executable(record main.cpp)
target_link_libraries(record PRIVATE Microsoft.GSL::GSL)
add_executable(main01 main01.cpp)
add_executable(main02 main02.cpp)
add_executable(main03 main03.cpp)
