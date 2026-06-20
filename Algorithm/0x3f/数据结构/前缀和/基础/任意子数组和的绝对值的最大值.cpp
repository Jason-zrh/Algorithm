#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        long long ans = 0, prefix = 0, premax = 0, premin = 0;
        for(auto x : nums) {
            prefix += x;
            premax = max(premax, prefix);
            premin = min(premin, prefix);
        }
        return premax - premin;
    }
};

