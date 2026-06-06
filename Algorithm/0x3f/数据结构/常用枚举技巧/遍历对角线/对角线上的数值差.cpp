#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        // k = i - j + n -> j = i - k + n
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int k = i - j + n;
                int min_j = max(n - k, 0);
                int max_j = min(m - 1 - k + n, n - 1);
                // i = j + k - n
                // 第一段
                unordered_map<int, int> mp1;
                int cnt1 = 0;
                for(int l = min_j; l < j; j++) {
                    if(mp1[grid[l + k - n][l]] == 0) {
                        cnt1++;
                    }
                    mp1[grid[l + k - n][l]]++;
                }

                // 第二段
                unordered_map<int, int> mp2;
                int cnt2 = 0;
                for(int l = j + 1; l <= max_j; l++) {
                    if(mp2[grid[l + k - n][l]] == 0) {
                        cnt2++;
                    }
                    mp2[grid[l + k - n][l]]++;
                }

                ans[i][j] = abs(cnt1 - cnt2);
            }
        }
        return ans;
    }
};