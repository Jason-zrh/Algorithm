#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 快慢指针: 内存O(1), 夯爆了
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast == NULL)
                return false;
            fast = fast->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

int main()
{

    return 0;
}