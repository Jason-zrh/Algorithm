#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        int j = 0, k = 0;
        int direction = 0;
        for(int i = 0; i < m * n; i++)
        {
            ans.emplace_back(matrix[j][k]);
            matrix[j][k] = INT_MAX;

            // 计算新下标
            int x = j + dx[direction];
            int y = k + dy[direction];
            if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] != INT_MAX)
            {
                j = x;
                k = y;
            }
            else
            {
                direction = (direction + 1) % 4;
                j += dx[direction];
                k += dy[direction];
            }
        }
        return ans;
    }
};