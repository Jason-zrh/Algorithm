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
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast == nullptr)
                return false;
            fast = fast->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
