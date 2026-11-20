/*

LC 118. Pascal's Triangle

You are given an integer numRows.

Return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it and the first and last number on each row must be equal to 1.

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]

*/

#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;

    for (int row = 0; row < numRows; row++) {
        vector<int> temp;
        temp.push_back(1); // first element is always 1

        int prev = 1;

        for (int col = 1; col < row+1; col++) {
            int curr = prev * (row - col +1) / col;
            temp.push_back(curr);
            prev = curr;
        }

        ans.push_back(temp);

    }
    
    return ans;
}

/* ------------------------------------------------ */

/*

LC 119. Pascal's Triangle II

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:
Input: rowIndex = 0
Output: [1]

Example 3:
Input: rowIndex = 1
Output: [1,1]

*/

vector<int> getRow(int rowIndex) {
    vector<int> ans;

    if (rowIndex == 0) {
        ans.push_back(1);
        return ans;
    }

    long long temp = 1;
    ans.push_back(1);

    for (int i = 1; i <= rowIndex; i++) {
        temp = temp * (rowIndex - i + 1);
        temp = temp / i;
        ans.push_back(temp);
    }

    return ans;
}