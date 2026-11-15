#include <iostream>
#include "dsa/arrays/arrays_.hpp"
#include "common/utils.hpp"

using namespace std;

int main() {
    int arr[] = {1, 0, 0, 2, 4};
    int n = 9;

    cout << "Original Array: " << endl;
    Utils::print_arrays(arr, n);

    move_all_zeroes_to_end(arr, n);

    cout << "\nAfter moving zeroes: " << endl;
    Utils::print_arrays(arr, n);

    return 0;
}
