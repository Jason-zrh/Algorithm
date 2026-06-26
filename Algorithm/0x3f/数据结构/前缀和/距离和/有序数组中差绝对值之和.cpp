#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> prefix(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            prefix[i] = nums[i - 1] + prefix[i - 1];
        }
        for(int i = 0; i < n; i++) {
            int left = nums[i] * i - prefix[i];
            int right = (prefix[n] - prefix[i + 1]) - nums[i] * (n - i - 1);
            ans[i] = left + right;
        }
        return ans;
    }
};

