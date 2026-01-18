#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *l1 = list1;
        ListNode *l2 = list2;

        // 保存新链表的尾
        ListNode *newlist = nullptr;
        ListNode *tail = nullptr;
        while (l1 != nullptr && l2 != nullptr)
        {
            // l1 值大于l2，则把l2插入newlist
            if (l1->val > l2->val)
            {
                ListNode *next = l2->next;
                if (newlist == nullptr)
                {
                    newlist = l2;
                    tail = newlist;
                    tail->next = nullptr;
                }
                else
                {
                    tail->next = l2;
                    tail = l2;
                    tail->next = nullptr;
                }
                l2 = next;
            }
            else
            {
                // l2大于等于l1,将l1的值插入
                // 原链表为空
                ListNode *next = l1->next;
                if (newlist == nullptr)
                {
                    newlist = l1;
                    tail = l1;
                    tail->next = nullptr;
                }
                else
                {
                    tail->next = l1;
                    tail = l1;
                    tail->next = nullptr;
                }
                l1 = next;
            }
        }

        if (l1 != nullptr)
        {
            if (newlist == nullptr)
                newlist = l1;
            else
                tail->next = l1;
        }

        if (l2 != nullptr)
        {
            if (newlist == nullptr)
                newlist = l2;
            else
                tail->next = l2;
        }

        return newlist;
    }
};

int main()
{

    return 0;
}