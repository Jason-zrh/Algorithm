#include <vector>
#include <iostream>

using namespace std;

// 死去的线性代数开始攻击我，先沿着主对角线进行翻转，再行翻转

// 遍历两次
void rotate(vector<vector<int>> &matrix)
{
    int row = matrix.size(), col = matrix[0].size();
    // 转置矩阵，遍历主对角线下面的元素
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < i; j++)
            swap(matrix[i][j], matrix[j][i]);
    }

    // 行翻转
    for(auto& e : matrix)
        reverse(e.begin(), e.end());
}

// 遍历一次，遍历对角线上面的元素，交换后该行元素不会改变
void rotate(vector<vector<int>> &matrix)
{
    int row = matrix.size(), col = matrix[0].size();
    for(int i = 0; i < row; i++)
    {
        for(int j = i; j < col; j++)
            swap(matrix[i][j], matrix[j][i]);
        
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{

    return 0;
}