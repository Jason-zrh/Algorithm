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
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类 the head node
     * @return ListNode类
     */

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(0); // 用哨兵节点简化代码逻辑
        ListNode *cur = dummy;             // cur 指向新链表的末尾
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
        return dummy->next;
    }

    ListNode* findMiddle(ListNode *head)
    {
        ListNode* pre = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        pre->next = nullptr; // 断开slow与前面的连接
        return slow;
    }
    
    ListNode *sortInList(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        // [1, 3, 2, 4]
        // 找到中间节点并分成两个链表: head[1, 3], head2[2, 4]
        ListNode* head2 = findMiddle(head);
        return mergeTwoLists(sortInList(head), sortInList(head2)); 
    }
};