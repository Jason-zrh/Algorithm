#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0, window = 0, maxS = 0;
        int left = 0, right = 0, n = customers.size();
        for(right = 0; right < n; right++)
        {
            // 先考虑grumpy = 0的情况
            if(grumpy[right] == 0)
                ans += customers[right];

            // 入窗口
            if(grumpy[right] == 1)
                window += customers[right];
            if(right - left + 1 < minutes)
                continue;;
            
            maxS = max(maxS, window);
            if(grumpy[left] == 1)
                window -= customers[left];
            left++;
        }
        return ans += maxS;
    }
};