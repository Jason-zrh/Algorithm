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

    TreeNode* head = nullptr;
    TreeNode* pre = nullptr;

    void dfs(TreeNode* root)
    {       
        if(root == nullptr)
            return;
        dfs(root->left);
        root->left = pre;
        if(pre)
            pre->right = root;
        else
            head = root;
        
        pre = root;
        dfs(root->right);
    }
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        if(pRootOfTree == nullptr)
            return nullptr;
        dfs(pRootOfTree);
        return head;
    }
};