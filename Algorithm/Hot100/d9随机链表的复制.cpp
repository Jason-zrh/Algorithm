#include <unordered_map>
#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    Node* ans = nullptr;
    Node* tail = nullptr;
    Node* it = head;
    unordered_map<Node*, Node*> mp;
    while(it)
    {
        Node* newNode = new Node(it->val);
        // 将新旧节点映射
        mp[it] = newNode;
        // 新节点的radom指向原节点的radom
        newNode->random = it->random;
        if(ans == nullptr)
            ans = newNode;
        else
            tail->next = newNode;

        tail = newNode;
        it = it->next;
    }

    it = ans;
    while(it)
    {
        // 改变指向
        it->random = mp[it->random];
        it = it->next;
    }
    return ans;
}