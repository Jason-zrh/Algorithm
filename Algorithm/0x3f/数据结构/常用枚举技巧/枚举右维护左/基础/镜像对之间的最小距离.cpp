#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int reverseNum(int num) {
        vector<int> bits;
        while(num / 10 != 0) {
            bits.emplace_back(num % 10);
            num /= 10;
        }
        bits.emplace_back(num);
        int bit = bits.size();
        reverse(bits.begin(), bits.end());
        long long mul = 1, res = 0;
        for(int i = 0; i < bit; i++) {
            res += bits[i] * mul;
            mul *= 10;
        }
        return res;
    }


    int minMirrorPairDistance(vector<int>& nums) {
        int res = 1e9;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(nums[i]) != mp.end()) {
                res = min(res, abs(mp[nums[i]] - i));
            }
            mp[reverseNum(nums[i])] = i;
        }
        return res == 1e9 ? -1 : res;
    }
};

