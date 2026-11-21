/*

LC 1. Two Sum

(Variation 1)

You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: The sum of nums[0] and nums[1] is 2 + 7 = 9, which equals the target. Therefore, the indices [0, 1] are returned.

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]
Explanation: The sum of nums[1] and nums[2] is 2 + 4 = 6, which equals the target. Therefore, the indices [1, 2] are returned.

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
Explanation: The sum of nums[0] and nums[1] is 3 + 3 = 6, which equals the target. Therefore, the indices [0, 1] are returned.

(Variation 2)

Return Yes if target is achievable, else return No - string type return

*/

#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

// Variation 1
vector<int> twoSum(vector<int> &nums, int target) {
    int n = nums.size();

    /*
        // Brute Force method - using two pointer

        int ans[2];

        for (int i = 0; i<len; i++) {
            for (int j = 1; j<len-1; j++) {
                if ((nums[i] + nums[j]) == target) {
                    ans.push_back[i];
                    ans.push_back[j];
                }
            }
        }

        return ans;

    */

    // Better - using hashing and map

    map<int, int> m;

    for (int i = 0; i < n; i++) {
        int num = nums[i];
        int more = target - num;

        if (m.find(more) != m.end())
        {
            return {m[more], i};
        }
        m[num] = i;
    }

    return {-1, -1};
}

// Variation 2 (Optimal - without using map - using sorting and greedy)
string twoSum2(vector<int> &nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int left = 0, right = n - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target) {
            return "YES";
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    return "NO";
}

