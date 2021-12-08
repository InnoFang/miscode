/*
 * @FileName   : basis.cu 
 * @CreateAt   : 2021/12/8
 * @Author     : Inno Fang
 * @Email      : innofang@yeah.net
 * @Description: 
 */
#include <cstdio>

struct Matrix {
    size_t width;
    size_t height;
    int *value;
};

__device__
int getValue( Matrix *matrix, size_t row, size_t col ) {
    return matrix->value[row * matrix->width + col];
}

__device__
void setValue( Matrix *matrix, size_t row, size_t col, int val ) {
    matrix->value[row * matrix->width + col] = val;
}

__global__
void matmul( Matrix *A, Matrix *B, Matrix *C ) {
    size_t row = blockIdx.y * blockDim.y + threadIdx.y;
    size_t col = blockIdx.x * blockDim.x + threadIdx.x;

    int val = 0;
    for ( size_t i = 0; i < A->width; ++ i ) {
        val += getValue(A, row, i) * getValue(B, i, col);
    }
    setValue( C, row, col, val );
}

int main() {

    Matrix *A, *B, *C;

    cudaMallocManaged( (void**)&A,  sizeof(Matrix) );
    cudaMallocManaged( (void**)&B,  sizeof(Matrix) );
    cudaMallocManaged( (void**)&C,  sizeof(Matrix) );

    size_t width = 1 << 5;
    size_t height = 1 << 5;

    A->width = width; A->height = height;
    B->width = width; B->height = height;
    C->width = width; C->height = height;

    size_t nBytes = width * height * sizeof(size_t);
    cudaMallocManaged( (void**)&A->value, nBytes );
    cudaMallocManaged( (void**)&B->value, nBytes );
    cudaMallocManaged( (void**)&C->value, nBytes );

    for ( int i = 0; i < width * height; ++ i ) {
        A->value[i] = 2;
        B->value[i] = 3;
    }

    dim3 blockSize( width, height );
    dim3 gridSize( (width + blockSize.x - 1) / blockSize.x, (height + blockSize.y - 1) / blockSize.y );

    matmul<<<gridSize, blockSize>>>( A, B, C );

    cudaDeviceSynchronize();

    for ( int i = 1; i <= width * height; ++ i ) {
        printf("%d ", C->value[i]);
        if ( i % width == 0 ) printf("\n");
    }
    printf("\n");

    cudaFree( A->value );
    cudaFree( B->value );
    cudaFree( C->value );
    cudaFree( A );
    cudaFree( B );
    cudaFree( C );

    return 0;
}