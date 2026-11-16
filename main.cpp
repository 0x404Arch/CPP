#include <vector>

#include "dsa/arrays/arrays_.hpp"
#include "common/utils.hpp"

using namespace std;

int main() {
    vector<int> num1 = {1, 2, 3, 4, 5};
    vector<int> num2 = {1, 2, 7};

    vector<int> ans = intersectionArray(num1, num2);
    Utils::print_vectors(ans);

    return 0;
}
