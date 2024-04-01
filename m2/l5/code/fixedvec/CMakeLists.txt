cmake_minimum_required(VERSION 3.27)
project(fixedvec LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
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

add_executable(main01 main01.cpp)
target_link_libraries(main01 PRIVATE Microsoft.GSL::GSL)
add_executable(main02 main02.cpp)
target_link_libraries(main02 PRIVATE Microsoft.GSL::GSL)
