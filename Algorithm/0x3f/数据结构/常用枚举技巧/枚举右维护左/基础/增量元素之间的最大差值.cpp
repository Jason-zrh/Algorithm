#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini = nums[0], res = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > mini) {
                res = max(res, nums[i] - mini);
            }
            mini = min(mini, nums[i]);
        }
        return res == 0 ? -1 : res;
    }
};