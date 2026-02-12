#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

// try BFS
class Solution
{
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int fresh = 0;
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                    fresh++;
                else if(grid[i][j] == 2)
                    // 向队列中添加待bfs的元素
                    q.push(make_pair(i, j));
            }
        }

        // 进行bfs
        while(fresh && !q.empty())
        {
            ans++;
            // 计算当层队列大小
            int len = q.size();
            for(int i = 0; i < len; i++)
            {
                pair<int, int> pr = q.front();
                q.pop();
                int x = pr.first, y = pr.second;
                for(int k = 0; k < 4; k++)
                {
                    int _x = x + dx[k];
                    int _y = y + dy[k];
                    // 周边有新鲜橘子
                    if(_x >= 0 && _x < m && _y >= 0 && _y < n && grid[_x][_y] == 1)
                    {
                        // 新鲜橘减一
                        fresh--;
                        grid[_x][_y] = 2;
                        q.push(make_pair(_x, _y));
                    }
                }
            }
        }

        return fresh ? -1 : ans;
    }
};