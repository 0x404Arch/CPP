#include "array_utils.hpp"
#include "swap_utils.hpp"

#include <iostream>

namespace utils {
    // Print array
    void print_arrays(int* arr, int n) {
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    // Manually delete a number from array
    void delete_num_from_array(int arr[], int& n, int index) {
        if (index < 0 || index >= n) return;

        for (int i = index; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        n--;
    }

    // Reverse an array
    void reverse_array(int arr[], int start, int end) {
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
}