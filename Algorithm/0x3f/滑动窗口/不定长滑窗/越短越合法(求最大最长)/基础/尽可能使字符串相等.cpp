#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cost = 0;
        int left = 0, right = 0, n = s.size();
        int ans = 0;
        for(right = 0; right < n; right++)
        {
            // 入窗口
            cost += abs(s[right] - t[right]);

            while(cost > maxCost)
            {
                cost -= abs(s[left] - t[left]);
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};