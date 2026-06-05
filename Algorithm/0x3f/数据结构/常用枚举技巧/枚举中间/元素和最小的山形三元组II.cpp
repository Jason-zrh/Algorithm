#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int ans = 1e9, n = nums.size();
        // nums[i] < nums[j] && nums[j] > nums[k]
        vector<int> suffixMin(n + 1, 1e9);
        for(int i = n - 1; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }
        int prefixMin = nums[0];
        for(int j = 1; j < n - 1; j++) {
            if(prefixMin < nums[j] && nums[j] > suffixMin[j + 1]){
                ans = min(ans, prefixMin + nums[j] + suffixMin[j + 1]);
            }
            prefixMin = min(prefixMin, nums[j]);
        }
        return ans == 1e9 ? -1 : ans;
    }
};

