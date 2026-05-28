#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        while(left < right)
        {
            ans = max(ans, min(height[left], height[right]) * (right - left));
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return ans;
    }
};
