#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int res = 1e9, pos1 = -1, pos2 = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                pos1 = i;
                if(pos2 != -1) {
                    res = min(res, abs(pos1 - pos2));
                }
            }
            if(nums[i] == 2) {
                pos2 = i;
                if(pos1 != -1) {
                    res = min(res, abs(pos1 - pos2));
                }
            }
        }
        return res == 1e9 ? -1 : res;
    }
};