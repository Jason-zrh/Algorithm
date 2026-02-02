#include <iostream>
#include <vector>
#include <algorithm>

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
    // 左闭右开
    TreeNode* build(vector<int> &inorder, int i_start, int i_end, 
                    vector<int> &postorder, int p_start, int p_end)
    {
        if(p_start == p_end)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[p_end - 1]);

        // 要计算右子树的大小了
        int index = i_start;
        while(index < i_end)
        {
            if(inorder[index] != postorder[p_end - 1])
                index++;
            else
                break;
        }
        int left_size = index - i_start;
        // int right_size = i_end - index - 1;
        root->left = build(inorder, i_start, index, 
                           postorder, p_start, p_start + left_size);

        root->right = build(inorder, index + 1, i_end, 
                            postorder, p_start + left_size, p_end - 1);
        
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};