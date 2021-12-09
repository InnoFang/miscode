#include <iostream>
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/sequence.h>
#include <thrust/copy.h>

#define DSIZE 10
#define FVAL 5

struct test_functor
{
    const int a;

    test_functor(int _a) : a(_a) {}

    __device__
    bool operator()(const int& x ) {
        return (x==a);
    }
};

int main(){
    int target_layer = FVAL;
    thrust::host_vector<int> h_vals(DSIZE);
    thrust::sequence(h_vals.begin(), h_vals.end());
    thrust::device_vector<int> d_vals = h_vals;
    thrust::device_vector<int> d_result(DSIZE);
    thrust::copy_if(d_vals.begin(), d_vals.end(), d_result.begin(),  test_functor(target_layer));
    thrust::host_vector<int> h_result = d_result;
    std::cout << "Data :" << std::endl;
    thrust::copy(h_vals.begin(), h_vals.end(), std::ostream_iterator<int>( std::cout, " "));
    std::cout << std::endl;
    std::cout << "Filter Value: " << target_layer << std::endl;
    std::cout << "Results :" << std::endl;
    thrust::copy(h_result.begin(), h_result.end(), std::ostream_iterator<int>( std::cout, " "));
    std::cout << std::endl;
    return 0;
}