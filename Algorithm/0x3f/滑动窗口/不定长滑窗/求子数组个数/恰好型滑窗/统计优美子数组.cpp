#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 判断奇
    bool isodd(int num) {
        return num % 2 != 0 ? true : false;
    }

    int solve(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        int left = 0, right = 0, cnt = 0;

        for(right = 0; right < n; right++) {
            if(isodd(nums[right]))
                cnt++;
            
            while(cnt >= k) {
                res += (n - right);
                if(isodd(nums[left])) {
                    cnt--;
                }
                left++;
            }
        }
        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k + 1);
    }
};

