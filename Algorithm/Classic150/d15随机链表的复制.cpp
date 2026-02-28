#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

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

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node*, Node*> mp;
        Node* ans = nullptr;
        Node* tail = nullptr;
        Node* pos = head;
        while(pos)
        {
            // 映射新旧节点
            Node* newNode = new Node(pos->val);
            mp[pos] = newNode;

            // 新节点random指向原节random
            newNode->random = pos->random;

            if(ans == nullptr)
                ans = newNode;
            else
                tail->next = newNode;
            tail = newNode;
            
            pos = pos->next;
        }

        pos = ans;
        while(pos)
        {
            pos->random = mp[pos->random];
            pos = pos->next;
        }

        return ans;
    }
};