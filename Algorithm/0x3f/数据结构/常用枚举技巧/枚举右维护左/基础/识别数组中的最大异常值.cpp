#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int total = 0; 
        for (int x : nums) {
            total += x;
            cnt[x]++;
        }
        int ans = INT_MIN;
        for (int sum : nums) {
            int outlier = total - 2 * sum;
            if (cnt.count(outlier) == 0) {
                continue;
            }
            // sum 和 outlier 必须来自不同下标
            if (outlier == sum && cnt[outlier] < 2) {
                continue;
            }
            ans = max(ans, outlier);
        }
        return ans;
    }
};
