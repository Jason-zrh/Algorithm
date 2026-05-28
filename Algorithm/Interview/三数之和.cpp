#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        // 排序，方便去重
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // 三数之和，要留两个位置
        for(int i = 0 ; i < n - 2; i++)
        {
            // 给i也去重，但是要保证它不是第一个
            if(i && nums[i] == nums[i - 1])
                continue;

            int j = i + 1, k = n - 1;
            while(j < k)
            {
                if(nums[j] + nums[k] > -nums[i])
                    k--;
                else if(nums[j] + nums[k] < -nums[i])
                    j++;
                else
                {
                    // 找到结果
                    ans.push_back({nums[i], nums[j], nums[k]});
                    // 对j，k去重
                    j++, k--;
                    while(j < k && nums[j] == nums[j - 1])
                        j++;
                    while(j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};