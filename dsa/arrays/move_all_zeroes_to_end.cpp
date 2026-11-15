#include "common/utils.hpp"

void move_all_zeroes(int arr[], int n)
{
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            Utils::swap(arr[pos], arr[i]);
            pos++;
        }
    }
}