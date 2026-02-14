#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 从后往前遍历nums1, nums2
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p1 = m - 1;
        int p2 = n - 1;
        int i = m + n - 1;

        while (p1 >= 0 && p2 >= 0)
        {
            if (nums1[p1] > nums2[p2])
                nums1[i--] = nums1[p1--];
            else

                nums1[i--] = nums2[p2--];
        }

        // 如果 nums2 还有剩余
        while (p2 >= 0)
            nums1[i--] = nums2[p2--];
    }
};