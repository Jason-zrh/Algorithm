#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        int left = 0, right = 0, n = fruits.size();
        int category = 0;
        unordered_map<int, int> mp;

        for(right = 0; right < n; right++)
        {
            int num = fruits[right];
            // 入窗口
            if(mp[num] == 0)
                category++;
            mp[num]++;

            while(category > 2)
            {
                num = fruits[left];
                mp[num]--;
                if(mp[num] == 0)
                    category--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};