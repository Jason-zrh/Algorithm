#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>> 
     * @return int整型
     */
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    
    void dfs(vector<vector<char> >& grid, int i, int j, vector<vector<bool >>& used)
    {
        used[i][j] = true;
        for(int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && used[x][y] == false && grid[x][y] == '1')
                dfs(grid, x, y, used);       
        }
    }

    int solve(vector<vector<char> >& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool >> used(m, vector<bool>(n, false));
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // dfs标记所有岛屿
                if(grid[i][j] == '1' && used[i][j] == false)
                {
                    dfs(grid, i, j, used);
                    ans++;
                }
                else
                    continue;
            }
        }
        return ans;
    }
};