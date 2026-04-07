#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.begin(), nums.end());

        vector<int> prefix(nums.size() + 1, 0);
        for(int i = 1; i <= nums.size(); i++)
            prefix[i] = prefix[i - 1] + nums[i - 1];
        
        for(int i = 0; i < queries.size(); i++)
        {
            int left = 0, right = nums.size(), mid = 0;
            while(left < right)
            {
                // 找最后一个前缀和小于等于queries的位置
                mid = (left + right + 1) / 2;
                if(prefix[mid] > queries[i])
                    right = mid - 1;
                else
                    left = mid;
            }
            ans.push_back(left);
        }
        return ans;
    }
};