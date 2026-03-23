#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// TLE
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int ans = 0;
//         unordered_set<int> st(nums.begin(), nums.end());
//         for(int i = 0; i < nums.size(); i++)
//         {
//             int len = 1;
//             int left = nums[i] - 1;
//             int right = nums[i] + 1;
//             while(st.contains(left) || st.contains(right))
//             {
//                 if(st.contains(left))
//                 {
//                     ++len;
//                     --left;
//                 }
//                 if(st.contains(right))
//                 {
//                     ++len;
//                     ++right;
//                 }
//             }
//             ans = max(ans, len);
//         }
//         return ans;
//     }
// };

// 模拟双指针
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        // 这里遍历的是st，自动去重了一次
        for(auto& x : st)
        {
            // 往左走还能走
            if(st.contains(x - 1))
                continue;
            int y = x + 1;
            // 一直找到最右边
            while(st.contains(y))
                y++;
            ans = max(ans, y - x);
        }
        return ans;
    }
};