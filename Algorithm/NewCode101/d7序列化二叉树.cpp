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
    char *Serialize(TreeNode *root)
    {
        if (!root)
        {
            char *res = new char[2];
            strcpy(res, "#");
            return res;
        }

        std::string s = "";
        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node)
            {
                s += std::to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                s += "#,";
            }
        }

        // 去掉末尾多余的逗号
        if (!s.empty())
            s.pop_back();

        // 申请堆空间并拷贝，符合 char* 返回要求
        char *res = new char[s.length() + 1];
        strcpy(res, s.c_str());
        return res;
    }

    // 反序列化：char* -> TreeNode*
    TreeNode *Deserialize(char *str)
    {
        if (!str || strcmp(str, "#") == 0)
            return nullptr;

        // 使用 vector 预先分割字符串，避免在循环中频繁操作指针
        std::vector<std::string> nodes;
        std::string s(str);
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(",")) != std::string::npos)
        {
            nodes.push_back(s.substr(0, pos));
            s.erase(0, pos + 1);
        }
        nodes.push_back(s); // 最后一个元素

        TreeNode *root = new TreeNode(std::stoi(nodes[0]));
        std::queue<TreeNode *> q;
        q.push(root);

        int i = 1; // 用于遍历 nodes 数组
        while (!q.empty() && i < nodes.size())
        {
            TreeNode *parent = q.front();
            q.pop();

            // 处理左孩子
            if (nodes[i] != "#")
            {
                parent->left = new TreeNode(std::stoi(nodes[i]));
                q.push(parent->left);
            }
            i++;

            // 处理右孩子 (需检查越界)
            if (i < nodes.size() && nodes[i] != "#")
            {
                parent->right = new TreeNode(std::stoi(nodes[i]));
                q.push(parent->right);
            }
            i++;
        }

        return root;
    }
};
