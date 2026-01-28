#include <iostream>
#include <vector>

using namespace std;

// 该矩阵特点: 从左到右升序，从上到下升序，所以可以从右上开始检索
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size(), col = matrix[0].size();
    int x = 0, y = col - 1;
    while (x < row && y >= 0)
    {
        if (matrix[x][y] == target)
            return true;
        if (matrix[x][y] > target)
        {
            y -= 1;
            continue;
        }
        if (matrix[x][y] < target)
        {
            x += 1;
            continue;
        }
    }
    return false;
}


int main()
{

    return 0;
}