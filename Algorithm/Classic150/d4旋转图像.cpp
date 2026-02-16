#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // 先按层反转，再按对角线反转
    void rotate(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            // j == i
            for (int j = i; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);

            // 按层反转
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};