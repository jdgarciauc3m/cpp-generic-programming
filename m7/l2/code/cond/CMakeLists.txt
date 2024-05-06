cmake_minimum_required(VERSION 3.28)
project(cond)

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

add_executable(cond main.cpp)
target_link_libraries(cond PRIVATE Microsoft.GSL::GSL)
