#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;



class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans(m * n);
        int dict = 0;
        int x = 0, y = 0;
        for(int i = 0; i < m * n; i++)
        {
            ans[i] = matrix[x][y];
            // 走过以后需要标记已经走过
            matrix[x][y] = INT_MAX;
            int j = x + dx[dict];
            int k = y + dy[dict];
            
            if(j >= 0 && j < m && k >= 0 && k < n && matrix[j][k] != INT_MAX)
                x = j, y = k;
            else
            {
                dict = (dict + 1) % 4;
                x += dx[dict];
                y += dy[dict];
            }

        }
        return ans;
    }
};