#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

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

class Solution {
public:
    TreeNode* build(vector<int>& preorder, int prbegin, int prend, vector<int>& postorder, int pobegin, int poend)
    {
        if(prbegin == prend)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[prbegin]);

        // if (prend - prbegin == 1)
        //     return root;

        int index = pobegin;
        while(index < poend)
        {
            if(postorder[index] != preorder[prbegin + 1])
                index++;
            else
                break;
        }

        int leftlen = index - pobegin + 1;
        root->left = build(preorder, prbegin + 1, prbegin + 1 + leftlen, postorder, pobegin, pobegin + leftlen);
        root->right = build(preorder, prbegin + 1 + leftlen, prend, postorder, pobegin + leftlen, poend - 1);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
    {
        return build(preorder, 0, preorder.size(), postorder, 0, postorder.size());
    }
};