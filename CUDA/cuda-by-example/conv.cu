/*
 * @FileName   : conv.cu
 * @CreateAt   : 2021/12/6
 * @Author     : Inno Fang
 * @Email      : innofang@yeah.net
 * @Description: implement basic convolution in CUDA
 */
#include <iostream>

#include <cuda.h>
#include <cuda_runtime.h>

#define WIDTH 1920
#define HEIGHT 1080
#define real float

static void HandleError(cudaError_t err, const char *file, int line) {
    if (err != cudaSuccess) {
        printf("%s in %s at line %d\n", cudaGetErrorString(err), file, line);
        exit(EXIT_FAILURE);
    }
}

#define HANDLE_ERROR(err) (HandleError(err, __FILE__, __LINE__))

int getThreadNum() {
    cudaDeviceProp prop;
    int count;

    HANDLE_ERROR( cudaGetDeviceCount(&count) );
    printf("GPU device count is %d\n", count);
    HANDLE_ERROR( cudaGetDeviceProperties(&prop, 0) );
    printf("Warp size is %d\n", prop.warpSize);
    printf("Max thread number per block is %d\n", prop.maxThreadsPerBlock);
    printf("Max block number per MultiProcessor is %d\n", prop.maxBlocksPerMultiProcessor);
    printf("The dimensions of grid is (%d, %d, %d)\n",
           prop.maxGridSize[0], prop.maxGridSize[1], prop.maxGridSize[2]);
    return prop.maxThreadsPerBlock;
}

__global__
void conv(real *img, real *kernel, real *result, int kernel_dim) {
    int id = threadIdx.x + (blockIdx.x * blockDim.x);
    if (id < WIDTH * HEIGHT) {
        int row = id / WIDTH;
        int col = id % WIDTH;
        for (int i = 0; i < kernel_dim; ++ i) {
            for (int j = 0; j < kernel_dim; ++ j) {
                real img_val = 0;
                int curr_row = row - kernel_dim / 2 + i;
                int curr_col = col - kernel_dim / 2 + j;
                if (0 <= curr_row && curr_row < HEIGHT && 0 <= curr_col && curr_col < WIDTH) {
                    img_val = img[curr_row * WIDTH + curr_col];
                }
                result[id] += kernel[i * kernel_dim + j] * img_val;
            }
        }
    }
}

int main() {

    /* INITIALIZE */

    real *img = new real[WIDTH * HEIGHT];
    for (int row = 0; row < HEIGHT; ++ row) {
        for (size_t col = 0; col < WIDTH; ++ col) {
            img[col + row * WIDTH] = static_cast<real>((col + row) % 256);
        }
    }

    int kernel_dim = 3;
    int kernel_size = kernel_dim * kernel_dim;
    real *kernel = new real[kernel_size];
    for (int i = 0; i < kernel_size; ++i) {
        kernel[i] = static_cast<real>(i % kernel_dim - 1); // each row is [-1 0 1]
    }


    real *img_d, *kernel_d, *result_d;
    HANDLE_ERROR( cudaMalloc((void**)&img_d, WIDTH * HEIGHT * sizeof(real)) );
    HANDLE_ERROR( cudaMalloc((void**)&kernel_d, kernel_size * sizeof(real)) );
    HANDLE_ERROR( cudaMalloc((void**)&result_d, WIDTH * HEIGHT * sizeof(real)) );

    HANDLE_ERROR( cudaMemcpy(img_d, img, WIDTH * HEIGHT * sizeof(real), cudaMemcpyHostToDevice) );
    HANDLE_ERROR( cudaMemcpy(kernel_d, kernel, kernel_size * sizeof(real), cudaMemcpyHostToDevice) );

    /* COMPUTING */

    int thread_num = getThreadNum();
    int block_num = ( WIDTH * HEIGHT + thread_num - 1 ) / thread_num;
    conv<<<block_num, thread_num>>>(img_d, kernel_d, result_d, kernel_dim);

    real *result = new real[WIDTH * HEIGHT];
    HANDLE_ERROR( cudaMemcpy(result, result_d, WIDTH * HEIGHT * sizeof(real), cudaMemcpyDeviceToHost) );

    /* DISPLAY */

    // print image
    printf("\nimage\n===========\n");
    for (int row = 0; row < 10; ++ row) {
        for (int col = 0; col < 10; ++ col) {
            printf("%3.0f", img[col + row * WIDTH]);
        }
        printf("\n");
    }

    // print kernel
    printf("\nkernel\n===========\n");
    for (int row = 0; row < kernel_dim; ++ row) {
        for (int col = 0; col < kernel_dim; ++ col) {
            printf("%3.0f", kernel[col + row * kernel_dim]);
        }
        printf("\n");
    }

    // print result
    printf("\nresult\n===========\n");
    for (size_t row = 0; row < 10; ++ row) {
        for (size_t col = 0; col < 10; ++ col) {
            printf("%3.0f", result[col + row * WIDTH]);
        }
        printf("\n");
    }

    cudaFree(img_d);
    cudaFree(kernel_d);
    cudaFree(result_d);

    free(img);
    free(kernel);
    free(result);

    return 0;
}

