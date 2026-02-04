#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int m, n;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    // dfs 返回 bool，表示“是否找到了路径”
    bool dfs(vector<vector<char>> &board, int x, int y, int pos, string &word)
    {
        // 1. 终止条件：全部字符匹配完毕
        if (pos == word.size())
            return true;
        

        // 2. 越界检查 或 字符不匹配
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != word[pos])
        {
            return false;
        }

        // 3. 标记访问
        // 为了省去 vis 数组，我们暂存当前字符，并将 board 对应位置改为特殊符号
        char temp = board[x][y];
        board[x][y] = '#'; // '#' 代表已访问

        // 4. 尝试四个方向
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            // 如果某一条路通了，直接返回 true，不再试其他方向
            if (dfs(board, nx, ny, pos + 1, word))
            {
                return true;
            }
        }

        // 5. 回溯（恢复现场）
        // 必须把字符改回来，否则影响后续搜索
        board[x][y] = temp;

        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // 从 (i, j) 开始尝试匹配
                // 这里 dfs 从 pos=0 开始，即在这个函数里判断 word[0]
                if (dfs(board, i, j, 0, word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};