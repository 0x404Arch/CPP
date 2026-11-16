#include <vector>
using namespace std;

// Intersection - only elements comon in both
vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    
    vector<int> ans;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (nums1[i] < nums2[j]) {
            i++;
        }
        else if (nums1[i] > nums2[j]) {
            j++;
        }
        else {
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
    }

    return ans;
}