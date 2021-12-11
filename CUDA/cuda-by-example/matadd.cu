/*
 * @FileName   : matadd.cu
 * @CreateAt   : 2021/12/11
 * @Author     : Inno Fang
 * @Email      : innofang@yeah.net
 * @Description: implement matrix addition in CUDA
 */

#include <cstdio>

static void HandleError(cudaError_t err, const char *file, int line) {
    if (err != cudaSuccess) {
        printf("%s in %s at line %d\n", cudaGetErrorString(err), file, line);
        exit(EXIT_FAILURE);
    }
}

#define HANDLE_ERROR(err) (HandleError(err, __FILE__, __LINE__))

#define N 64

__global__
void gpu(int *a, int *b, int *c_gpu) {
    size_t r = threadIdx.x + blockIdx.x * blockDim.x;
    size_t c = threadIdx.y + blockIdx.y * blockDim.y;

    if (r < N && c < N) {
        c_gpu[r * N + c] = a[r * N + c] + b[r * N + c];
    }
}

void cpu(int *a, int *b, int *c_cpu) {
    for (int r = 0; r < N; ++ r) {
       for (int c = 0; c < N; ++ c) {
           c_cpu[r * N + c] = a[r * N + c] + b[r * N + c];
       }
    }
}

bool check(int *c_cpu, int *c_gpu) {
    for (int r = 0; r < N; ++ r) {
        for (int c = 0; c < N; ++ c) {
            if (c_cpu[r * N + c] != c_gpu[r * N + c]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int *a, *b, *c_cpu, *c_gpu;
    size_t size = N * N * sizeof(int);

    HANDLE_ERROR( cudaMallocManaged((void**)&a, size) );
    HANDLE_ERROR( cudaMallocManaged((void**)&b, size) );
    HANDLE_ERROR( cudaMallocManaged((void**)&c_cpu, size) );
    HANDLE_ERROR( cudaMallocManaged((void**)&c_gpu, size) );

    /* initialize */
    for (int r = 0; r < N; ++ r) {
        for (int c = 0; c < N; ++ c) {
            a[r * N + c] = r;
            a[r * N + c] = c;
            c_cpu[r * N + c] = 0;
            c_gpu[r * N + c] = 0;
        }
    }

    dim3 threads(16, 16, 1);
    dim3 blocks((N + threads.x - 1) / threads.x, (N + threads.y - 1) / threads.y, 1);

    gpu<<<blocks, threads>>>(a, b, c_gpu);
    cudaDeviceSynchronize();
    cpu(a, b, c_cpu);

    check(c_cpu, c_gpu) ? printf("passed\n") : printf("failed\n");

    HANDLE_ERROR( cudaFree(a) );
    HANDLE_ERROR( cudaFree(b) );
    HANDLE_ERROR( cudaFree(c_cpu) );
    HANDLE_ERROR( cudaFree(c_gpu) );

    return 0;
}

