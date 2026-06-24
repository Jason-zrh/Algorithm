#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefix = 0, ans = 0;
        for (int x : nums) {
            prefix += x;
            int rem = (prefix % k + k) % k;
            ans += mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};

