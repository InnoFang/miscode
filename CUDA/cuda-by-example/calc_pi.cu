/*
 * @FileName   : basis.cu 
 * @CreateAt   : 2021/12/6
 * @Author     : Inno Fang
 * @Email      : innofang@yeah.net
 * @Description: 
 */
#include <iostream>
#include <ctime>

#define N 1000000
#define real float
#define CUDA_KERNEL_LOOP(i, n) \
        for (int i = blockIdx.x * blockDim.x + threadIdx.x; \
            i < (n);           \
            i += blockDim.x * gridDim.x)

static void HandleError(cudaError_t err, const char *file=__FILE__, int line=__LINE__) {
    if (err != cudaSuccess) {
        printf("%s in %s at line %d\n", cudaGetErrorString(err), file, line);
        exit(EXIT_FAILURE);
    }
}

#define HANDLE_ERROR(err) (HandleError(err, __FILE__, __LINE__))

__global__
void distance(real *x, real *y, real *result) {
    CUDA_KERNEL_LOOP(idx, N) {
        real temp = (x[idx] - 1) * (x[idx] - 1) + (y[idx] - 1) * (y[idx] - 1);
        result[idx] = temp < 1 ? 1.0 : 0;
    }
}

__global__
void sum(real *a, real *b) {
    __shared__ real sData[512];
    b[0] = 0;
    size_t tid = threadIdx.x;
    int boundary = static_cast<int>(ceilf(N / 512));
    for (int count = 0; count < boundary; ++count) {
        if (tid + count * 512 < N) {
            sData[tid] = a[tid + count * 512];
            __syncthreads();
        }
        for (int i = 256; i > 0; i >>= 1) {
            if (tid < i && tid + count * 512 < N) {
                sData[tid] = sData[tid] + sData[tid + i];
            }
            __syncthreads();
        }
        if (tid == 0) {
            b[0] += sData[0];
        }
    }
}

int main() {
    srand(time(nullptr));
    real *x_square = new float[N];
    real *y_square = new float[N];

    for (int i = 0; i < N; ++ i) {
        x_square[i] = static_cast<real>(rand() % 10000 * 1.0 / 10000);
        y_square[i] = static_cast<real>(rand() % 10000 * 1.0 / 10000);
    }

    real *x_square_d, *y_square_d;
    HANDLE_ERROR( cudaMalloc( (void**)&x_square_d, N * sizeof(real) ) );
    HANDLE_ERROR( cudaMalloc( (void**)&y_square_d, N * sizeof(real) ) );
    HANDLE_ERROR( cudaMemcpy(x_square_d, x_square, N * sizeof(real), cudaMemcpyHostToDevice) );
    HANDLE_ERROR( cudaMemcpy(y_square_d, y_square, N * sizeof(real), cudaMemcpyHostToDevice) );

    int block_num = 512;
    int thread_num = 1024;
    real *result_d;
    HANDLE_ERROR( cudaMalloc( (void**)&result_d, N * sizeof(real) ) );
    distance<<<block_num, thread_num>>>(x_square_d, y_square_d, result_d);

    real *result = new real[N];
    HANDLE_ERROR( cudaMemcpy(result, result_d, N * sizeof(real), cudaMemcpyDeviceToHost) );

    real *b_d;
    HANDLE_ERROR( cudaMalloc( (void**)&b_d, 1 * sizeof(real) ) );
    sum<<<1, 512, 512>>>(result_d, b_d);

    real b[1];
    HANDLE_ERROR( cudaMemcpy(b, b_d, 1 * sizeof(real), cudaMemcpyDeviceToHost) );
    printf("b: %f\n", b[0]);
    printf("pi: %f\n", b[0] * 4.0 / N);

    cudaFree(x_square_d);
    cudaFree(y_square_d);
    cudaFree(result_d);
    cudaFree(b_d);

    free(x_square);
    free(y_square);
    free(result);
    return 0;
}

