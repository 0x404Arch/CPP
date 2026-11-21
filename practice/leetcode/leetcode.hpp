#pragma once

#include <vector>
#include <string>

// LC 1: Two Sum
std::vector<int> twoSum (std::vector<int>& nums, int target); // Variation 1
std::string twoSum2(std::vector<int> &nums, int target); // Variation 2

// LC 54: Spiral Matrix
std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix);

// LC 118: Pascal's Triangle
std::vector<std::vector<int>> generate(int numRows);

// LC 119: Pascal's Triangle II
std::vector<int> getRow(int rowIndex);

// LC: 2149. Rearrange Array Elements by Sign
std::vector<int> rearrangeArray(std::vector<int> &nums);
