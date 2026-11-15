#include <set>
#include <vector>
using namespace std;

// Method 1: Using a set
vector<int> unionArray(vector<int> &num1, vector<int> &num2)
{
    set<int> s;

    for (vector<int>::size_type i = 0; i < num1.size(); i++)
    {
        s.insert(num1[i]);
    }

    for (vector<int>::size_type i = 0; i < num2.size(); i++)
    {
        s.insert(num2[i]);
    }

    vector<int> ans(s.begin(), s.end());

    return ans;
}

// Method 2: without using a set
vector<int> unionArray2(vector<int> &nums1, vector<int> &nums2)
{
    int i = 0, j = 0;
    int n = nums1.size();
    int m = nums2.size();

    vector<int> ans;

    while (i < n && j < m)
    {
        if (nums1[i] <= nums2[j])
        {
            if (ans.empty() || ans.back() != nums1[i])
            {
                ans.push_back(nums1[i]);
            }
            i++;
        }
        else
        {
            if (ans.empty() || ans.back() != nums2[j])
            {
                ans.push_back(nums2[j]);
            }
            j++;
        }
    }

    while (i < n)
    {
        if (ans.empty() || ans.back() != nums1[i])
        {
            ans.push_back(nums1[i]);
        }
        i++;
    }

    while (j < m)
    {
        if (ans.empty() || ans.back() != nums2[j])
        {
            ans.push_back(nums2[j]);
        }
        j++;
    }

    return ans;
}