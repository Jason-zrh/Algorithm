#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pRoot TreeNode类
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
            return {};
        vector<vector<int>> ans;
        deque<TreeNode* > dq;
        dq.push_back(pRoot);
        int dir = 0;
        while (!dq.empty())
        {
            vector<int> level;
            int n = dq.size();
            if (dir == 0)
            {
                // 从左往右
                for (int i = 0; i < n; i++)
                {
                    TreeNode *front = dq.front();
                    level.push_back(front->val);
                    dq.pop_front();
                    if(front->left)
                        dq.push_back(front->left);
                    if(front->right)
                        dq.push_back(front->right);
                }
                ans.push_back(level);
                dir = (dir + 1) % 2;
            }
            else
            {
                // 从右往左
                for (int i = 0; i < n; i++)
                {
                    TreeNode *back = dq.back();
                    level.push_back(back->val);
                    dq.pop_back();
                    if(back->right)
                        dq.push_front(back->right);
                    if(back->left)
                        dq.push_front(back->left);
                }
                ans.push_back(level);
                dir = (dir + 1) % 2;
            }
        }
        return ans;
    }
};