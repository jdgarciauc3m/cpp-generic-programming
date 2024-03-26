cmake_minimum_required(VERSION 3.27)
project(fixedvec)

set(CMAKE_CXX_STANDARD 23)

add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors -Wsign-conversion)
add_compile_options(-lstdc++_libbacktrace -llibstdc++exp)

include(FetchContent)

FetchContent_Declare(GSL
        GIT_REPOSITORY "https://github.com/microsoft/GSL"
        GIT_TAG "v4.0.0"
        GIT_SHALLOW ON
)
FetchContent_MakeAvailable(GSL)

add_executable(fixedvec main.cpp)
target_link_libraries(fixedvec PRIVATE Microsoft.GSL::GSL)
