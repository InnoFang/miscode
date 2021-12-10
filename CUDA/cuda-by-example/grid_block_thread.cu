/*
 * @FileName   : grid_block_thread.cu
 * @CreateAt   : 2021/12/10
 * @Author     : Inno Fang
 * @Email      : innofang@yeah.net
 * @Description: learn how to get thread id in vary
 *               the dimension of the grid and the dimension of the block
 */

#include <cstdio>

__device__
size_t getDim1BlockId() {
    return blockIdx.x;
}

__device__
size_t getDim2BlockId() {
    return blockIdx.x
           + blockIdx.y * gridDim.x;
}

__device__
size_t getDim3BlockId() {
    return blockIdx.x
           + blockIdx.y * gridDim.x
           + blockIdx.z * gridDim.x * gridDim.y;
}

__device__
size_t getDim1ThreadId(size_t block_id) {
    return threadIdx.x
           + block_id * blockDim.x;
}

__device__
size_t getDim2ThreadId(size_t block_id) {
    return threadIdx.x
           + threadIdx.y * blockDim.x
           + block_id * blockDim.x * blockDim.y * blockDim.z;
}

__device__
size_t getDim3ThreadId(size_t block_id) {
    return threadIdx.x
           + threadIdx.y * blockDim.x
           + threadIdx.z * blockDim.x * blockDim.y
           + block_id * blockDim.x * blockDim.y * blockDim.z;
}

__device__
size_t getTheadId(size_t grid_dim = 1, size_t block_dim = 1) {
    if (grid_dim == 1 && block_dim == 1) return getDim1ThreadId(getDim1BlockId());
    if (grid_dim == 1 && block_dim == 2) return getDim1ThreadId(getDim2BlockId());
    if (grid_dim == 1 && block_dim == 3) return getDim1ThreadId(getDim3BlockId());
    if (grid_dim == 2 && block_dim == 1) return getDim2ThreadId(getDim1BlockId());
    if (grid_dim == 2 && block_dim == 2) return getDim2ThreadId(getDim2BlockId());
    if (grid_dim == 2 && block_dim == 3) return getDim2ThreadId(getDim3BlockId());
    if (grid_dim == 3 && block_dim == 1) return getDim3ThreadId(getDim1BlockId());
    if (grid_dim == 3 && block_dim == 2) return getDim3ThreadId(getDim2BlockId());
    return getDim3ThreadId(getDim3BlockId());
}

__global__
void kernel() {
    size_t tid = getTheadId();
    printf("[log] thread idx: %lld\n", tid);
}

int main() {
    kernel<<<2, 3>>>();
    return 0;
}