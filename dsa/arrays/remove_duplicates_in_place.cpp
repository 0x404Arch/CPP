#include <bits/stdc++.h>
#include "utils/array_utils.hpp"

using namespace std;

// Without using a set
void remove_duplicates_in_place_from_sorted(int arr[], int n) {
    if (n == 0) return;

    int j = 0; 

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    int unique_count = j + 1;

    cout << "Unique Array: ";

    utils::print_arrays(arr, unique_count);
}