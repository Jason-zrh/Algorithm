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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = dummy;

        for (int i = 0; i < n; i++)
            fast = fast->next;

        while (fast)
        {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }

        prev->next = slow->next;
        delete slow;
        return dummy->next;
    }
};