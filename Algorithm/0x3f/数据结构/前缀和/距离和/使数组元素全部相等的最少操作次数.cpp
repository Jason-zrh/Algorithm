#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    // 二分 >= k的第一个下标
    int lower_bound(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n - 1, mid = 0;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] < k) {
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return left;
    }
    
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int m = queries.size();
        vector<long long> ans(m);
        // 先排序
        sort(nums.begin(), nums.end());
        vector<long long> prefix(nums.size() + 1, 0);
        for(int i = 1; i <= nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        } 
        for(int i = 0; i < m; i++) {
            int pos = lower_bound(nums, queries[i]);
            if(pos == nums.size()) {
                ans[i] = nums.size() * queries[i] - prefix[nums.size()];
                continue;
            }
            long long left = 1LL * queries[i] * pos - prefix[pos];
            long long right = 1LL * (prefix[nums.size()] - prefix[pos]) - queries[i] * (nums.size() - pos);
            ans[i] = left + right;
        }
        return ans;
    }
};

