#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int left = 0, right = n - 1;
        while(left < right)
        {
            if(height[left] < height[right])
            {
                ans = max(ans, height[left] * (right - left));
                left++;
            }
            else
            {
                ans = max(ans, height[right] * (right - left));
                right--;
            }
        }
        return ans;
    }
};