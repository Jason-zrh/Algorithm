#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<long long>> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        vector<long long> ans(n);
        for(auto it = mp.begin(); it != mp.end(); it++) {
            vector<long long> group = it->second;
            vector<long long> prefix(group.size() + 1, 0);
            for(int i = 1; i <= group.size(); i++) {
                prefix[i] = prefix[i - 1] + group[i - 1];
            }

            for(int i = 0; i < group.size(); i++) {
                long long left = group[i] * i - prefix[i];
                long long right = (prefix[group.size()] - prefix[i + 1]) - group[i] * (group.size() - i - 1);
                ans[group[i]] = left + right;
            }
        }
        return ans;
    }
};