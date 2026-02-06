#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int f[n + 1], g[n + 1];
        f[0] = g[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            f[i] = g[i - 1] + nums[i - 1];
            g[i] = max(g[i - 1], f[i - 1]);
        }
        return max(f[n], g[n]);
    }
};