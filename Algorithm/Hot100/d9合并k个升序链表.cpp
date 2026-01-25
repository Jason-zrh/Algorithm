#include <vector>

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
        ListNode dummy;         // 用哨兵节点简化代码逻辑
        ListNode *cur = &dummy; // cur 指向新链表的末尾
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                cur->next = list1; // 把 list1 加到新链表中
                list1 = list1->next;
            }
            else
            {                      // 注：相等的情况加哪个节点都是可以的
                cur->next = list2; // 把 list2 加到新链表中
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2; // 拼接剩余链表
        return dummy.next;
    }

    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        ListNode *ans = nullptr;
        for (int i = 0; i < lists.size(); i++)
        {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }
};