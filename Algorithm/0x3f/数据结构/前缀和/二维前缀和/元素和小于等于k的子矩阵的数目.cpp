#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }
        int ans = 0;
        for(int x = 0; x < m; x++) {
            for(int y = 0; y < n; y++) {
                int sum = prefix[x + 1][y + 1] - prefix[0][y + 1] - prefix[x + 1][0] + prefix[0][0];
                if(sum <= k)
                    ans++;
            }
        }
        return ans;
    }
};

