#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 前后缀积秒了
        int n = nums.size();
        vector<int> ans(n);

        vector<int> prefix(n + 1, 1);
        vector<int> suffix(n + 1, 1);
        for(int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
            suffix[n - i] = suffix[n - i + 1] * nums[n - i];
        }
        for(int i = 0; i < n; i++)
            ans[i] = prefix[i] * suffix[i + 1];
        return ans;
    }
};