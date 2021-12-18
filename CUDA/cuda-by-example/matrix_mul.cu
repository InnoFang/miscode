/*
 * @FileName   : matmul.cu
 * @CreateAt   : 2021/12/8
 * @Author     : Inno Fang
 * @Email      : innofang@yeah.net
 * @Description: implement matrix multiply in CUDA
 */
#include <cstdio>
#include <cmath>

#define HANDLE_ERROR(err)                         \
do {                                              \
    if (err != cudaSuccess) {                     \
        printf("CUDA Error:\n");                  \
        printf("    File:       %s\n", __FILE__); \
        printf("    Line:       %d\n", __LINE__); \
        printf("    Error code: %d\n", err);      \
        printf("    Error text: %s\n",            \
                cudaGetErrorString(err));         \
        exit(1);                                  \
    }                                             \
} while (0)

struct Matrix {
    size_t width;
    size_t height;
    int *value;
};

__global__
void gpu_mat_mul(Matrix *A, Matrix *B, Matrix *C) {
    size_t row = blockIdx.y * blockDim.y + threadIdx.y;
    size_t col = blockIdx.x * blockDim.x + threadIdx.x;

    int value = 0;
    if (col < A->width && row < B->height) {
        for (size_t k = 0; k < C->width; ++k) {
            value += A->value[row * A->width + k] * B->value[k * B->height + col];
        }
        C->value[row * C->width + col] = value;
    }
}

void cpu_mat_mul(Matrix *A, Matrix *B, Matrix *C) {
    for (int row = 0; row < B->height; ++row) {
        for (int col = 0; col < A->width; ++col) {
            int value = 0;
            for (int k = 0; k < C->width; ++k) {
                value += A->value[row * A->width + k] * B->value[k * B->height + col];
            }
            C->value[row * C->width + col] = value;
        }
    }
}

bool check(Matrix *A, Matrix *B) {
    for (int row = 0; row < A->height; ++row) {
        for (int col = 0; col < A->width; ++col) {
            if (fabs(A->value[row * A->width + col] - B->value[row * B->width + col]) > (1.0e-10)) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    Matrix *hostA, *hostB, *hostC, *hostCC;
    Matrix *devA, *devB, *devC;

    size_t height = 1 << 5;
    size_t width = 1 << 5;
    size_t nBytes = width * height * sizeof(size_t);
    HANDLE_ERROR(cudaMallocHost((void **) &hostA, sizeof(Matrix)));
    HANDLE_ERROR(cudaMallocHost((void **) &hostB, sizeof(Matrix)));
    HANDLE_ERROR(cudaMallocHost((void **) &hostC, sizeof(Matrix)));
    HANDLE_ERROR(cudaMallocHost((void **) &hostCC, sizeof(Matrix)));

    hostA->width = width; hostA->height = height;
    hostB->width = width; hostB->height = height;
    hostC->width = width; hostC->height = height;
    hostCC->width = width; hostCC->height = height;
    HANDLE_ERROR(cudaMallocHost((void **) &hostA->value, nBytes));
    HANDLE_ERROR(cudaMallocHost((void **) &hostB->value, nBytes));
    HANDLE_ERROR(cudaMallocHost((void **) &hostC->value, nBytes));
    HANDLE_ERROR(cudaMallocHost((void **) &hostCC->value, nBytes));

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            hostA->value[i * width + j] = rand() % 1024 + 1;
        }
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            hostB->value[i * width + j] = rand() % 1024 + 1;
        }
    }

    HANDLE_ERROR(cudaMalloc((void **) &devA, sizeof(Matrix)));
    HANDLE_ERROR(cudaMalloc((void **) &devB, sizeof(Matrix)));
    HANDLE_ERROR(cudaMalloc((void **) &devC, sizeof(Matrix)));
    HANDLE_ERROR(cudaMemcpy(devA, hostA, sizeof(Matrix), cudaMemcpyHostToDevice));
    HANDLE_ERROR(cudaMemcpy(devB, hostB, sizeof(Matrix), cudaMemcpyHostToDevice));
    HANDLE_ERROR(cudaMemcpy(devC, hostC, sizeof(Matrix), cudaMemcpyHostToDevice));

    dim3 blockSize(width, height);
    dim3 gridSize((width + blockSize.x - 1) / blockSize.x, (height + blockSize.y - 1) / blockSize.y);

    cudaEvent_t start, stop_cpu, stop_gpu;
    HANDLE_ERROR(cudaEventCreate(&start));
    HANDLE_ERROR(cudaEventCreate(&stop_gpu));
    HANDLE_ERROR(cudaEventCreate(&stop_cpu));

    HANDLE_ERROR(cudaEventRecord(start));
    gpu_mat_mul<<<gridSize, blockSize>>>(devA, devB, devC);
    HANDLE_ERROR(cudaMemcpy(hostC, devC, sizeof(Matrix), cudaMemcpyDeviceToHost));
    HANDLE_ERROR(cudaGetLastError());
    HANDLE_ERROR(cudaEventRecord(stop_gpu));
    HANDLE_ERROR(cudaEventSynchronize(stop_gpu));

    cpu_mat_mul(hostA, hostB, hostCC);
    HANDLE_ERROR(cudaEventRecord(stop_cpu));
    HANDLE_ERROR(cudaEventSynchronize(stop_cpu));

    float elapsed_time_cpu, elapsed_time_gpu;
    HANDLE_ERROR(cudaEventElapsedTime(&elapsed_time_gpu, start, stop_gpu));
    HANDLE_ERROR(cudaEventElapsedTime(&elapsed_time_cpu, stop_gpu, stop_cpu));
    printf("GPU Time = %g ms.\n", elapsed_time_gpu);
    printf("CPU Time = %g ms.\n", elapsed_time_cpu);

    check(hostC, hostCC) ? printf("passed") : printf("failed");

    HANDLE_ERROR(cudaEventDestroy(start));
    HANDLE_ERROR(cudaEventDestroy(stop_cpu));
    HANDLE_ERROR(cudaEventDestroy(stop_gpu));

    HANDLE_ERROR(cudaFree(devA));
    HANDLE_ERROR(cudaFree(devB));
    HANDLE_ERROR(cudaFree(devC));

    HANDLE_ERROR(cudaFreeHost(hostA->value));
    HANDLE_ERROR(cudaFreeHost(hostB->value));
    HANDLE_ERROR(cudaFreeHost(hostC->value));
    HANDLE_ERROR(cudaFreeHost(hostA));
    HANDLE_ERROR(cudaFreeHost(hostB));
    HANDLE_ERROR(cudaFreeHost(hostC));

    return 0;
}