#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        // 找nums[i] + 1和 nums[i] - 1
        int ans = 0;
        for(auto x : st)
        {   
            if(st.contains(x - 1))
                continue;
            int y = x + 1;
            while(st.contains(y))
                y++;

            ans = max(ans, y - x);
        }
        return ans;
    }
};