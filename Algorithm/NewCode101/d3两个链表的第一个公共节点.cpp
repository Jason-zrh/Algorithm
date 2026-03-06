#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        unordered_map<ListNode*, ListNode*> mp;
        ListNode* p1 = pHead1;
        while(p1)
        {
            mp[p1] = p1;
            p1 = p1->next;
        }
        ListNode* p2 = pHead2;
        while(p2)
        {
            if(mp[p2] == p2)
                return p2;
            p2 = p2->next;
        }
        return nullptr;
    }
};