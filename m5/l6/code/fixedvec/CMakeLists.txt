cmake_minimum_required(VERSION 3.28)
project(fixedvec)

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

add_library(fixedvec STATIC fixed_vector.cpp)
target_link_libraries(fixedvec Microsoft.GSL::GSL)

add_library(numbers STATIC numbers.cpp)
target_link_libraries(numbers Microsoft.GSL::GSL fixedvec)

#add_executable(main01 main.cpp)
add_executable(main main.cpp)
target_link_libraries(main Microsoft.GSL::GSL numbers)
