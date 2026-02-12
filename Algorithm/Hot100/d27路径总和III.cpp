#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 思路与和为k的子数组相似
class Solution
{
public:
    int ans = 0;
    unordered_map<long long, int> mp;
    
    // s 代表从根节点到root节点的父节点的前缀和
    void dfs(TreeNode *root, int targetSum, long long s)
    {
        if(root == nullptr)
            return;
        
        s += root->val;
        ans += mp[s - targetSum];
        mp[s]++;
        dfs(root->left, targetSum, s);
        dfs(root->right, targetSum, s);
        mp[s]--;
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        // 给0一个初始化
        mp[0] = 1;
        dfs(root, targetSum, 0);
        return ans;
    }
};