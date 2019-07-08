cmake_minimum_required(VERSION 3.10)

# project name
project(cu_tutor_matmul CUDA CXX)
set(CMAKE_BUILD_TYPE Debug)

# define CXX_STD_11
if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED True)
endif()

# define cuda standard
if (NOT DEFINED CMAKE_CUDA_STANDARD)
    set(CMAKE_CUDA_STANDARD 11)
    set(CMAKE_CUDA_STANDARD_REQUIRED True)
endif()

# all srcs
set(cuda_files gpu_add.cu)
set(main_files main.cpp)

# lib
add_library(cuda_lib ${cuda_files})

# add exec
add_executable(matmul ${main_files})

# target lib
target_link_libraries(matmul cuda_lib)

# cuda specific
target_include_directories(matmul PRIVATE ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES})