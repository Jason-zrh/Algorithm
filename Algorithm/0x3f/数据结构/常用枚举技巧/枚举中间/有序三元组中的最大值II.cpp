#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int> suffix(n + 1, 0);
        for(int i = n - 1; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], nums[i]);
        }
        int prefix = nums[0];
        for(int i = 1; i < n - 1; i++) {
            long long num = 1LL * (prefix - nums[i]) * suffix[i + 1];
            if(num >= 0) {
                ans = max(ans, num);
            }
            prefix = max(prefix, nums[i]);
        }
        return ans;
    }
};

