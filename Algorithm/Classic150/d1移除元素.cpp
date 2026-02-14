#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                ans++;
                nums[i] = 51;
            }
        }
        sort(nums.begin(), nums.end());
        return nums.size() - ans;
    }
};