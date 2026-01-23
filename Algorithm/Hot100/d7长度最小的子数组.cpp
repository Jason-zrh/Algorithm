#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int ans = INT_MAX;
    int left = 0, sum = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        sum += nums[right];
        while (sum - nums[left] >= target)
        {
            sum -= nums[left];
            left++;
        }
        if (sum >= target)
            ans = min(ans, right - left + 1);
    }
    return ans == INT_MAX ? 0 : ans;
}