#include "utils/swap_utils.hpp"

#include <vector>

using namespace std;

// Selection sort
void selection_sort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {

        int minIndex = i;

        // Find index of minimum element
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap actual elements in arr
        utils::swap(arr[i], arr[minIndex]);
    }
}