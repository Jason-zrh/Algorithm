#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int digitalSum(int num) {
        int sum = 0;
        while((num / 10) != 0) {
            sum += num % 10;
            num /= 10;
        }
        sum += num;
        return sum;
    }


    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            int sum = digitalSum(nums[i]);
            if(mp.find(sum) != mp.end()) {
                res = max(res, mp[sum] + nums[i]);
            }
            mp[sum] = max(mp[sum], nums[i]);
        }
        return res == 0 ? -1 : res;
    }
};