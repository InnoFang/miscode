#include <iostream>
#include "leapfrog.hpp"

int main() {
    std::vector<int> v1 { 1, 2, 3, 10 };
    std::vector<int> v2 { 2, 10 };
    std::vector<int> v3 { 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    std::vector<std::vector<int>> vs { v1, v2, v3 };

    auto res = LFJ::leapfrogJoin( vs );
    std::cout << res.size() << " elements in the intersection:" << std::endl;
    for( int el : res )
        std::cout << "\t" << el << std::endl;
    return 0;
}
