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
     * @return bool布尔型
     */

    bool validate(TreeNode *node, int minVal, int maxVal)
    {
        if (node == nullptr)
            return true;

        // 检查当前节点是否超出了它应该存在的范围
        if (node->val <= minVal || node->val >= maxVal)
            return false;

        // 递归左子树：最大值更新为当前节点值
        // 递归右子树：最小值更新为当前节点值
        return validate(node->left, minVal, node->val) &&
               validate(node->right, node->val, maxVal);
    }

    bool isValidBST(TreeNode *root)
    {
        // 使用 long long 以防止节点值等于 INT_MIN 或 INT_MAX 时的边界溢出
        return validate(root, INT_MIN, INT_MAX);
    }
};
