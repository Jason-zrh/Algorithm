#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 找第一个和最后一个0的位置
    // >= 0的第一个位置
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

    int maximumCount(vector<int>& nums) {
        // 第一个 >= 0的位置
        int start = lower_bound(nums, 0);
        // 所有值都 < 0
        if(start == nums.size()) {
            return start;
        }
        // 没有0
        if(nums[start] != 0) {
            return max(start, ((int)nums.size() - start));
        }

        // 找最后一个0的位置
        int end = lower_bound(nums, 1);
        return max(start, ((int)nums.size() - end));
    }
};