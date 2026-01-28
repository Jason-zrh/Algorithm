#include <vector>
#include <iostream>

using namespace std;

// x, y
int dx[4] = {0, 1, 0, -1}; // 右下左上
int dy[4] = {1, 0, -1, 0};

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int row = matrix.size(), col = matrix[0].size();
    int x = 0, y = 0, dirc = 0; // 初始坐标, 和初始方向
    for(int i = 0; i < row * col; i++) //一共走row * col步
    {
        ans.push_back(matrix[x][y]);
        matrix[x][y] = INT_MAX; // 标记走过

        // 计算新下标
        int p = x + dx[dirc];
        int q = y + dy[dirc];
        
        // 判断是否超出边界或被访问过 !!! 边界条件要仔细判断 !!!
        if(p < 0 || p >= row || q < 0 || q >= col || matrix[p][q] == INT_MAX)
            dirc = (dirc + 1) % 4; // 旋转90
        
        x += dx[dirc];
        y += dy[dirc];
    }
    return ans;
}

int main()
{

    return 0;
}