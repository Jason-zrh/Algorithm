#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        for(int x = 0; x < m; x++) {
            for(int y = 0; y < n; y++) {
                int row1 = max(0, x - k), col1 = max(0, y - k), row2 = min(m - 1, x + k), col2 = min(n - 1, y + k);
                ans[x][y] = prefix[row2 + 1][col2 + 1] + prefix[row1][col1] - prefix[row1][col2 + 1] - prefix[row2 + 1][col1];
            }
        }
        return ans;
    }
};

