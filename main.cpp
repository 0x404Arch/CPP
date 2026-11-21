#include <iostream>
#include <vector>

#include "practice/leetcode/leetcode.hpp"
#include "common/utils.hpp"

using namespace std;

int main() {

    vector<int> nums = {2, 11, 7, 15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);
    Utils::print_vectors(ans);

    string answer = twoSum2(nums, target);
    cout << answer << endl;

    return 0;
}
