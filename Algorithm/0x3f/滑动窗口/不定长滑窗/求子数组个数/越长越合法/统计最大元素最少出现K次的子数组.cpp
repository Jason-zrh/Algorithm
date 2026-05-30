#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }
        long long res = 0, cnt = 0;
        int left = 0, right = 0;
        for(right = 0; right < n; right++) {
            if(nums[right] == maxi) {
                cnt++;
            }

            while(cnt >= k) {
                res += (n - right);
                if(nums[left] == maxi) {
                    cnt--;
                }
                left++;
            }
        }
        return res;
    }
};