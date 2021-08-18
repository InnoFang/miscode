#include <thrust/device_vector.h>
#include <thrust/transform.h>
#include <thrust/sequence.h>
#include <thrust/copy.h>
#include <thrust/fill.h>
#include <thrust/replace.h>
#include <thrust/functional.h>
#include <iostream>
#include <chrono>

struct saxpy_functor {
    const float a;
    saxpy_functor(float _a): a(_a) {}

    __host__ __device__
    float operator()(const float& x, const float& y) const {
        return a * x + y;
    }
};

void saxpy_fast(float A, thrust::device_vector<float>& X, thrust::device_vector<float>& Y) {
    // Y <- A * X + Y
    thrust::transform(X.begin(), X.end(), Y.begin(), Y.begin(), saxpy_functor(A));
}

void saxpy_slow(float A, thrust::device_vector<float>& X, thrust::device_vector<float>& Y) {
    thrust::device_vector<float> temp(X.size());

    // temp <- A
    thrust::fill(temp.begin(), temp.end(), A);

    // temp <- A * X
    thrust::transform(X.begin(), X.end(), temp.begin(), temp.begin(), thrust::multiplies<float>());

    // Y <- A * X + Y
    thrust::transform(temp.begin(), temp.end(), Y.begin(), Y.begin(), thrust::plus<float>());
}

int main() {
    const float A = 2;
    thrust::device_vector<float> X(10);
    thrust::device_vector<float> Y(10);

    thrust::sequence(X.begin(), X.end());
    thrust::fill(Y.begin(), Y.end(), 1);

    auto start_time = std::chrono::high_resolution_clock::now();
    saxpy_slow(A, X, Y);
    double used_time = std::chrono::duration_cast<std::chrono::duration<double>>(
            std::chrono::high_resolution_clock::now() - start_time)
            .count();
    std::cout << "saxpy_slow used time: " << used_time << std::endl;


    thrust::sequence(X.begin(), X.end());
    thrust::fill(Y.begin(), Y.end(), 1);

    start_time = std::chrono::high_resolution_clock::now();
    saxpy_fast(A, X, Y);
    used_time = std::chrono::duration_cast<std::chrono::duration<double>>(
            std::chrono::high_resolution_clock::now() - start_time)
            .count();
    std::cout << "saxpy_slow used time: " << used_time << std::endl;

    return 0;
}