#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 先按照对角线交换，再每行反转
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < row; i++) 
        {
            for (int j = i; j < col; j++)
                swap(matrix[i][j], matrix[j][i]);

            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};