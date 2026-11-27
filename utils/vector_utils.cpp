#include "vector_utils.hpp"
#include <iostream>

namespace utils {
    // Print vector
    void print_vectors(const std::vector<int>& arr) {
        for (int num : arr) {
            std::cout << num << " ";
        }
        
        std::cout << std::endl;
    }
}