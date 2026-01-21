// 耻辱下播，改天再战
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        for (auto &e : nums2)
            nums1.push_back(e);
        sort(nums1.begin(), nums1.end());

        if ((nums1.size() % 2) == 0)
            return (double)(nums1[nums1.size() / 2] + nums1[(nums1.size() / 2) - 1]) / 2;
        else
            return nums1[nums1.size() / 2];
    }
};

int main()
{

    return 0;
}