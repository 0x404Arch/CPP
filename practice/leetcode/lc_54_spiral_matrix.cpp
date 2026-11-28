/*

LC 54: Spiral Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

*/

#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size();    // number of rows
    int m = matrix[0].size(); // number of columns

    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;

    vector<int> ans;

    // Movement: right -> bottom -> left -> top

    while (top <= bottom && left <= right)
    {
        // Right
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }

        top++;

        // Bottom
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }

        right--;

        // Left
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }

            bottom--;
        }

        // Top
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }

            left++;
        }
    }

    return ans;
}