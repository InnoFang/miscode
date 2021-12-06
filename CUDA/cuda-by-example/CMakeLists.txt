cmake_minimum_required(VERSION 3.19)
project(cuda_by_example CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(basis basis.cu)
set_target_properties(basis PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
