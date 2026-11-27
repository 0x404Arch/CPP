#include "swap_utils.hpp"

namespace utils {
    // Swap 2 numbers
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Swap 2 characters
    void swap(char &a, char &b) {
        char temp = a;
        a = b;
        b = temp;
    }
    
} // namespace utils
