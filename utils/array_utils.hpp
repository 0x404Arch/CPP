#pragma once

namespace utils {
    // Print arrays
    void print_arrays(int *arr, int n);

    // manually delete a number from array
    void delete_num_from_array(int arr[], int &n, int index);

    // Reverse an array
    void reverse_array(int arr[], int start, int end);
} // namespace utils