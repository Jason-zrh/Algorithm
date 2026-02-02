#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 上下左右

class Solution
{
public:
    // 标记数组
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    vector<vector<bool>> vis;
    int m, n;

    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        // 更改标记位置
        vis[i][j] = true;
        // 计算上下左右下标位置
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] &&
                grid[x][y] == '1')
                dfs(grid, x, y);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int cnt = 0;
        m = grid.size(), n = grid[0].size();
        vis = vector<vector<bool>>(m, vector<bool>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};