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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *pos = head;
        while (pos && pos->next)
        {

            if (pos->val == pos->next->val)
                pos->next = pos->next->next;
            else
                pos = pos->next;
        }
        return head;
    }
};