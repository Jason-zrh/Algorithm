#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int left = 0, right = 0, window = 0, ans = 1e9;
        int sum = 0;
        for(right = 0; right < n; right++)
        {
            sum += cardPoints[right];
            window += cardPoints[right];
            if(right - left + 1 < (n - k))
                continue;
            ans = min(ans, window);
            window -= cardPoints[left];
            left++;
        }
        if(n == k)
            return sum;
        return sum - ans;
    }
};