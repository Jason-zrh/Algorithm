#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        for(int i = 0; i < spells.size(); i++)
        {
            int left = 0, right = potions.size(), mid = 0;
            while(left < right)
            {
                mid = (left + right) / 2;
                long long tmp = (long long)potions[mid] * spells[i];
                // 找第一个potions * spell >= success的
                if(tmp >= success)
                    right = mid;
                else
                    left = mid + 1;
            }

            // 可能不存在
            if(left == potions.size())
                ans.push_back(0);
            else
                ans.push_back(potions.size() - left);
        }
        return ans;
    }
};