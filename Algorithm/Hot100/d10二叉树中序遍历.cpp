#include <queue>
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

// vector<vector<int>> levelOrder(TreeNode *root)
// {
//     if (root == nullptr)
//         return {};
//     vector<vector<int>> ans;
//     queue<TreeNode *> q;
//     // 插入节点
//     q.push(root);
//     while (!q.empty())
//     {
//         vector<int> level;
//         for (int i = 0; i < q.size(); i++) // 这里不应该直接用q.size(), 在下面出入队列的时候条件一直在改变
//         {
//             // 先出队列，再将左右子节点分别添加到队列中
//             TreeNode *front = q.front();
//             level.push_back(front->val);
//             q.pop();
//             if (front->left)
//                 q.push(front->left);
//             if (front->right)
//                 q.push(front->right);
//         }
//         ans.push_back(level);
//     }
//     return ans;
// }

vector<vector<int>> levelOrder(TreeNode *root)
{
    if (root == nullptr)
        return {};
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    // 插入节点
    q.push(root);
    while (!q.empty())
    {
        vector<int> level;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            // 先出队列，再将左右子节点分别添加到队列中
            TreeNode *front = q.front();
            q.pop();
            level.push_back(front->val);
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
        ans.push_back(level);
    }
    return ans;
}