#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    if (k <= 1)
        return 0;
    int ans = 0;
    int left = 0, mul = 1;
    for (int right = 0; right < nums.size(); right++)
    {
        mul *= nums[right];
        while (mul >= k)
        {
            mul /= nums[left];
            left++;
        }
        ans += (right - left + 1);
    }
    return ans;
}
