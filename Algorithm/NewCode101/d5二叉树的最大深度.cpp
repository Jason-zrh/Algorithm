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
     * @param root TreeNode类
     * @return int整型
     */

    int ans = 0;

    void dfs(TreeNode *root, int depth)
    {
        if(root == nullptr)
        {
            ans = max(ans, depth);
            return;
        }

        depth++;
        dfs(root->left, depth);
        dfs(root->right, depth);
    }

    int maxDepth(TreeNode *root)
    {
        dfs(root, 0);
        return ans;
    }
};