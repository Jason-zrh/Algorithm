#include <iostream>
#include <vector>

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

class Solution
{
public:
    // 左闭右闭区间
    TreeNode* constructTree(vector<int> &nums, int left, int right)
    {
        if(left > right)
            return nullptr;

        int mid = (left + right + 1) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = constructTree(nums, left, mid - 1);
        root->right = constructTree(nums, mid + 1, right);
    }

    TreeNode* sortedArrayToBST(vector<int> &nums)
    {
        return constructTree(nums, 0, nums.size() - 1);
    }
};