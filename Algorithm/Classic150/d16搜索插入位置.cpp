#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        int mid = 0;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};