#include <vector>

#include "practice/leetcode/leetcode.hpp"
#include "common/utils.hpp"

using namespace std;

int main() {

    vector<vector<int>> matrix = {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}
    };

    vector<int> ans = spiralOrder(matrix);
    Utils::print_vectors(ans);

    return 0;
}
