#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long res = 0;  
        unordered_map<int, int> mp;
        // j - i != nums[j] - nums[i] -> j - nums[j] != i - nums[i]
        for(int i = 0; i < nums.size(); i++) {
            int n = i - nums[i];
            res += i - mp[n];
            mp[n]++;
        }
        return res;
    }
};