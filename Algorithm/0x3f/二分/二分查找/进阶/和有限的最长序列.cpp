#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lower_bound(vector<int>& nums, int x) {
        int left = 0, right = nums.size() - 1, mid = 0;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] < x) {
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return left;
    }

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> res;
        sort(nums.begin(), nums.end());

        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for(int i = 0; i < queries.size(); i++) {
            int num = queries[i];
            int pos = lower_bound(prefix, num + 1) - 1;
            if(pos == -1) {
                res.emplace_back(0);
            }else {
                res.emplace_back(pos + 1);
            }
        }
        return res;
    }
};