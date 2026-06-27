#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    // >= k
    int lower_bound(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1, mid = 0;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }


    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = queries.size();
        vector<int> ans(n);

        sort(nums.begin(), nums.end());
        vector<int> prefix(nums.size() + 1, 0);
        for(int i = 1; i <= nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        
        for(int i = 0; i < n; i++) {
            int pos = lower_bound(prefix, queries[i] + 1) - 1;
            if(pos == -1) {
                ans[i] = 0;
            }else {
                ans[i] = pos;
            }
        }
        return ans;
    }
};