#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums) {
        vector<int> prefix(nums.size() + 1, 0);
        for(int i = 1; i <= nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            int start = max(0, i - nums[i]);
            ans += (prefix[i + 1] - prefix[start]);
        }
        return ans;
    }
};
