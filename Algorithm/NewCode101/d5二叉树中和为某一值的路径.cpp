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

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        // 1. 空树处理
        if (root == nullptr) return false;
        
        // 2. 到达叶子节点（左右子树都为空）
        // 判断当前节点的值是否等于剩下的目标和
        if (root->left == nullptr && root->right == nullptr) {
            return sum == root->val;
        }
        
        // 3. 递归向下寻找，减去当前节点值
        // 只要左子树或右子树有一条路径成立即可
        return hasPathSum(root->left, sum - root->val) || 
               hasPathSum(root->right, sum - root->val);
    }
};