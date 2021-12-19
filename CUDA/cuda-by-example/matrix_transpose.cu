/*
 * @FileName   : matrix_transpose.cu 
 * @CreateAt   : 2021/12/19
 * @Author     : Inno Fang
 * @Email      : innofang@yeah.net
 * @Description: matrix transpose
 */

#include <cstdio>

#define CHECK(err)                                \
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

#ifdef USE_DP
typedef double real;
#else
typedef float real;
#endif

#define NUM_REPEATS 10
#define TILE_DIM 32
#define N 10000
#define N2 (N * N)

__global__
void transpose1(const real *A, real *B) {
    const unsigned int nx = threadIdx.x + blockIdx.x * blockDim.x;
    const unsigned int ny = threadIdx.y + blockIdx.y * blockDim.y;
    if (nx < N && ny < N) {
        // READ coalesced WRITE uncoalesced
        B[nx * N + ny] = A[ny * N + nx];
    }
}

__global__
void transpose2(const real *A, real *B) {
    const unsigned int nx = threadIdx.x + blockIdx.x * blockDim.x;
    const unsigned int ny = threadIdx.y + blockIdx.y * blockDim.y;
    if (nx < N && ny < N) {
        // READ uncoalesced WRITE coalesced
        B[ny * N + nx] = A[nx * N + ny];
    }
}

__global__
void transpose3(const real *A, real *B) {
    const unsigned int nx = threadIdx.x + blockIdx.x * blockDim.x;
    const unsigned int ny = threadIdx.y + blockIdx.y * blockDim.y;
    if (nx < N && ny < N) {
        // READ uncoalesced WRITE coalesced
        B[ny * N + nx] = __ldg(&A[nx * N + ny]);
    }
}

__global__
void transpose4(const real *A, real *B) {
    __shared__ real S[TILE_DIM][TILE_DIM];
    unsigned int bx = blockIdx.x * TILE_DIM;
    unsigned int by = blockIdx.y * TILE_DIM;

    unsigned int nx1 = bx + threadIdx.x;
    unsigned int ny1 = by + threadIdx.y;
    if (nx1 < N && ny1 < N) {
        S[threadIdx.y][threadIdx.x] = A[ny1 * N + nx1];
    }
    __syncthreads();

    unsigned int nx2 = bx +threadIdx.x;
    unsigned int ny2 = by +threadIdx.y;
    if (nx2 < N && ny2 < N) {
        B[nx2 * N + ny2] = S[threadIdx.x][threadIdx.y];
    }
}

__global__
void transpose5(const real *A, real *B) {
    __shared__ real S[TILE_DIM][TILE_DIM + 1];
    unsigned int bx = blockIdx.x * TILE_DIM;
    unsigned int by = blockIdx.y * TILE_DIM;

    unsigned int nx1 = bx + threadIdx.x;
    unsigned int ny1 = by + threadIdx.y;
    if (nx1 < N && ny1 < N) {
        S[threadIdx.y][threadIdx.x] = A[ny1 * N + nx1];
    }
    __syncthreads();

    unsigned int nx2 = bx +threadIdx.x;
    unsigned int ny2 = by +threadIdx.y;
    if (nx2 < N && ny2 < N) {
        B[nx2 * N + ny2] = S[threadIdx.x][threadIdx.y];
    }
}

void timing(const real *d_A, real *d_B, const int task) {
    const unsigned grid_size_x = (N + TILE_DIM - 1) / TILE_DIM;
    const unsigned grid_size_y = grid_size_x;
    const dim3 block_size(TILE_DIM, TILE_DIM);
    const dim3 grid_size(grid_size_x, grid_size_y);

    float t_sum = 0;
    float t2_sum = 0;
    for (int repeat = 0; repeat <= NUM_REPEATS; ++repeat) {
        cudaEvent_t start, stop;
        CHECK(cudaEventCreate(&start));
        CHECK(cudaEventCreate(&stop));
        CHECK(cudaEventRecord(start));
        cudaEventQuery(start);

        if (task == 1) transpose1<<<grid_size, block_size>>>(d_A, d_B);
        else if (task == 2) transpose2<<<grid_size, block_size>>>(d_A, d_B);
        else if (task == 3) transpose3<<<grid_size, block_size>>>(d_A, d_B);
        else if (task == 4) transpose4<<<grid_size, block_size>>>(d_A, d_B);
        else if (task == 5) transpose5<<<grid_size, block_size>>>(d_A, d_B);
        else {
            printf("Error: wrong task\n");
            exit(1);
        }

        CHECK(cudaEventRecord(stop));
        CHECK(cudaEventSynchronize(stop));

        float elapsed_time;
        CHECK(cudaEventElapsedTime(&elapsed_time, start, stop));
        printf("Time = %g ms.\n", elapsed_time);

        if (repeat > 0) {
            t_sum += elapsed_time;
            t2_sum += elapsed_time * elapsed_time;
        }

        CHECK(cudaEventDestroy(start));
        CHECK(cudaEventDestroy(stop));
    }

    const float t_ave = t_sum / NUM_REPEATS;
    const float t_err = sqrt(t2_sum / NUM_REPEATS - t_ave * t_ave);
    printf("Time = %g +- %g ms.", t_ave, t_err);
}

void print_matrix(const real *A) {
    for (int ny = 0; ny < N; ny++) {
        for (int nx = 0; nx < N; nx++) {
            printf("%g\t", A[ny * N + nx]);
        }
        printf("\n");
    }
}

int main() {
    const int M = sizeof(real) * N2;
    real *h_A = (real *) malloc(M);
    real *h_B = (real *) malloc(M);
    for (int n = 0; n < N2; ++n) {
        h_A[n] = n;
    }
    real *d_A, *d_B;
    CHECK(cudaMalloc((void **) &d_A, M));
    CHECK(cudaMalloc((void **) &d_B, M));
    CHECK(cudaMemcpy(d_A, h_A, M, cudaMemcpyHostToDevice));

    printf("\ntranspose with coalesced read:\n");
    timing(d_A, d_B, 1);
    printf("\ntranspose with coalesced write:\n");
    timing(d_A, d_B, 2);
    printf("\ntranspose with coalesced write and __ldg read:\n");
    timing(d_A, d_B, 3);
    printf("\ntranspose with shared memory bank conflict:\n");
    timing(d_A, d_B, 4);
    printf("\ntranspose without shared memory bank conflict:\n");
    timing(d_A, d_B, 5);

    CHECK(cudaMemcpy(h_B, d_B, M, cudaMemcpyDeviceToHost));
    if (N <= 10) {
        printf("A =\n");
        print_matrix(h_A);
        printf("B =\n");
        print_matrix(h_B);
    }

    free(h_A);
    free(h_B);
    CHECK(cudaFree(d_A));
    CHECK(cudaFree(d_B));
    return 0;
}