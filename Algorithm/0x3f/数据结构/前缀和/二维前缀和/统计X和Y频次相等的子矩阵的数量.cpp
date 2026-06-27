#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> Xprefix(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> Yprefix(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(grid[i - 1][j - 1] == 'X') {
                    Xprefix[i][j] = Xprefix[i][j - 1] + Xprefix[i - 1][j] - Xprefix[i - 1][j - 1] + 1;
                }else {
                    Xprefix[i][j] = Xprefix[i][j - 1] + Xprefix[i - 1][j] - Xprefix[i - 1][j - 1];
                }

                if(grid[i - 1][j - 1] == 'Y') {
                    Yprefix[i][j] = Yprefix[i][j - 1] + Yprefix[i - 1][j] - Yprefix[i - 1][j - 1] + 1;
                }else {
                    Yprefix[i][j] = Yprefix[i][j - 1] + Yprefix[i - 1][j] - Yprefix[i - 1][j - 1];
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(Xprefix[i + 1][j + 1] > 0 && Xprefix[i + 1][j + 1] == Yprefix[i + 1][j + 1]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};