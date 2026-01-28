#include <iostream>
#include <vector>

using namespace std;


// 各开一个布尔数组
void setZeroes(vector<vector<int>> &matrix)
{
    int row = matrix.size(), col = matrix[0].size();
    vector<bool> row_zero(row, false);
    vector<bool> col_zero(col, false);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
                row_zero[i] = col_zero[j] = true;
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (row_zero[i] || col_zero[j])
                matrix[i][j] = 0;
        }
    }
}


int main()
{
    return 0;
}