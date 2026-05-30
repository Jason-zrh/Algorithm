#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // >= x
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

    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums, target);
    }
};