struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() 
    :val(0)
    ,left(nullptr)
    ,right(nullptr) 
    { }
    
    TreeNode(int x) 
    :val(x)
    ,left(nullptr)
    ,right(nullptr) 
    { }

    TreeNode(int x, TreeNode *left, TreeNode *right) 
    :val(x)
    ,left(left)
    ,right(right) 
    { }
};

bool isSym(TreeNode *left, TreeNode *right)
{

    if (left == nullptr && right == nullptr)
        return true;

    if (!left || !right)
        return false;

    if (left->val != right->val)
        return false;

    return isSym(left->right, right->left) &&
           isSym(left->left, right->right);
}

bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
        return true;

    return isSym(root->left, root->right);
}