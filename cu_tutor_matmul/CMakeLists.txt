cmake_minimum_required(VERSION 3.10)

# project name
project(cu_tutor_matmul CUDA CXX)

# define CXX_STD_11
if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED True)
endfi()

# define CUDA to use CXX_STD_11
if (NOT DEFINED CMAKE_CUDA_STANDARD)
    set(CMAKE_CUDA_STANDARD 11)
    set(CMAKE_CUDA_STANDARD_REQUIRED True)
endif()

# define all source files, for each .cu and .cpp
set(cuda_files matmul.cu)
set(cpp_files main.cpp)

# create a lib (optional)
add_library(cuda_lib ${cuda_files})

# build target (as exe)
add_executable(matmul main.cpp)

# link the target to all dependancies
target_link_libraries(matmul cuda_lib)

# specific additional parameters to cmake