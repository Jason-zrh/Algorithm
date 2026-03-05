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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* cur = head;

        while(cur)
        {
            if(cur->next && cur->val == cur->next->val)
            {
                // 处理删除整段
                int val = cur->val;
                while(cur && cur->val == val)
                    cur = cur->next;
                prev->next = cur;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};