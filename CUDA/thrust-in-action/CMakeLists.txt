cmake_minimum_required(VERSION 3.15)
project(thrust_in_action CUDA CXX)

set(CMAKE_CUDA_STANDARD 14)

add_executable(thrust01 thrust01.cu)
set_target_properties(thrust01 PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

add_executable(thrust02 thrust02.cu)
set_target_properties(thrust02 PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

add_executable(thrust03 thrust03.cu)
set_target_properties(thrust03 PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

add_executable(thrust04 thrust04.cu)
set_target_properties(thrust04 PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

add_executable(thrust05 thrust05.cu)
set_target_properties(thrust05 PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

add_executable(thrust06 thrust06.cu)
set_target_properties(thrust06 PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

add_executable(thrust07 thrust07.cu)
set_target_properties(thrust07 PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

add_executable(thrust08 thrust08.cu)
set_target_properties(thrust08 PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

