/*
 * @FileName   : grid_block_thread2.cu
 * @CreateAt   : 2021/12/10
 * @Author     : Inno Fang
 * @Email      : innofang@yeah.net
 * @Description: implement the way of getting the thread id in vary
 *               the dimension of the grid and the dimension of the block
 */

#include <cstdio>

#define BID_IN_GRID1 blockIdx.x
#define BID_IN_GRID2 (BID_IN_GRID1 + blockIdx.y * gridDim.x)
#define BID_IN_GRID3 (BID_IN_GRID2 + blockIdx.z * gridDim.x * gridDim.y)

#define TID_IN_BLOCK1(BLOCK_ID) (threadIdx.x \
                                    + BLOCK_ID * blockDim.x)
#define TID_IN_BLOCK2(BLOCK_ID) (threadIdx.x \
                                    + threadIdx.y * blockDim.x \
                                    + BLOCK_ID * blockDim.x * blockDim.y * blockDim.z);
#define TID_IN_BLOCK3(BLOCK_ID) (threadIdx.x \
                                    + threadIdx.y * blockDim.x \
                                    + threadIdx.z * blockDim.x * blockDim.y \
                                    + BLOCK_ID * blockDim.x * blockDim.y * blockDim.z)

__global__
void kernel() {
    size_t tid = TID_IN_BLOCK3(BID_IN_GRID2);
    printf("[log] thread idx: %lld\n", tid);
}

int main() {
    dim3 block_num(1, 2);
    dim3 thread_num(2, 3, 2);
    kernel<<<block_num, thread_num>>>();
    return 0;
}