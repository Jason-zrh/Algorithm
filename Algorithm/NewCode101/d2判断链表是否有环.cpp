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
    bool hasCycle(ListNode *head)
    {
        unordered_map<ListNode*, int> mp;
        ListNode* pos = head;
        while(pos)
        {
            auto it = mp.find(pos);
            if(it != mp.end())
                return true;
            else
                mp[pos]++;
            
            pos = pos->next;
        }
        return false;
    }
};