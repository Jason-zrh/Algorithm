#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int prefix = 0;
        int ret = 0;
        unordered_map<int, int> mp; // 前缀和，出现次数
        mp[0] = 1;
        for(int i = 0; i < n; i++)
        {
            prefix += nums[i];
            ret += mp[prefix - k];
            mp[prefix]++;
        }
        return ret;
    }
};