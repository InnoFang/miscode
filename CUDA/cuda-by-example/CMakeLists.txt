cmake_minimum_required(VERSION 3.19)
project(cuda_by_example CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(grid_block_thread grid_block_thread.cu)
set_target_properties(grid_block_thread PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

add_executable(grid_block_thread2 grid_block_thread2.cu)
set_target_properties(grid_block_thread2 PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

add_executable(basis basis.cu)
set_target_properties(basis PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

add_executable(conv conv.cu)
set_target_properties(conv PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

add_executable(calc_pi calc_pi.cu)
set_target_properties(calc_pi PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

add_executable(matmul matmul.cu)
set_target_properties(matmul PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

add_executable(matadd matadd.cu)
set_target_properties(matadd PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

add_executable(device_props device_props.cu)
set_target_properties(device_props PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

add_executable(single_stream single_stream.cu)
set_target_properties(single_stream PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
