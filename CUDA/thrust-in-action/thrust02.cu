#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <iostream>

int main() {
    // H has storage for 4 integers
    thrust::host_vector<int> H(4);

    // initialize individual elements
    H[0] = 14;
    H[1] = 24;
    H[2] = 34;
    H[3] = 44;

    // H.size() return the size of vector H
    std::cout << "H has size " << H.size() << std::endl;

    //print contents of H
    for (int i = 0; i < H.size(); ++ i) {
        std::cout << "H[" << i << "] = " << H[i] << std::endl;
    }

    // resize H
    H.resize(2);

    std::cout << "H now has size " << H.size() << std::endl;

    // Copy host_vector H to device_vector D
    thrust::device_vector<int> D = H;

    // elements of D can be modified
    D[0] = 55;
    D[1] = 66;

    //print contents of D
    for (int i = 0; i < D.size(); ++ i) {
        std::cout << "D[" << i << "] = " << D[i] << std::endl;
    }

    // H and D are automatically destroyed when the function returns
    return 0;
}