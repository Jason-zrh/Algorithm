#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;


class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int k = 1; k < m + n; k++) {
            // 核心：计算 j 的最小值和最大值
            int min_j = max(n - k, 0); // i=0 的时候，j=n-k，但不能是负数
            int max_j = min(m + n - 1 - k, n - 1); // i=m-1 的时候，j=m+n-1-k，但不能超过 n-1
            vector<int> v;
            for (int j = min_j; j <= max_j; j++) {
                v.push_back(grid[k + j - n][j]); // 根据 k 的定义得 i=k+j-n
            }
            if (min_j > 0) { // 右上角三角形
                sort(v.begin(), v.end());
            } else { // 左下角三角形（包括中间对角线）
                sort(v.begin(), v.end());
                reverse(v.begin(), v.end());
            }
            for (int j = min_j; j <= max_j; j++) {
                grid[k + j - n][j] = v[j - min_j];
            }
        }
        return grid;
    }
};


