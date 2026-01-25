#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 回家等通知版
ListNode *sortList(ListNode *head)
{
    vector<int> nums;
    ListNode *it = head;
    while (it)
    {
        nums.push_back(it->val);
        it = it->next;
    }
    sort(nums.begin(), nums.end());
    it = head;
    for (int i = 0; i < nums.size(); i++)
    {
        it->val = nums[i];
        it = it->next;
    }
    return head;
}

// 归并排序（分治）
// 找到链表的中间结点 head 的前一个节点，并断开 head 与其前一个节点的连接。
// 这样我们就把原链表均分成了两段更短的链表。
// 分治: 递归调用 sortList，分别排序 head（只有前一半）和 head。
// 排序后，我们得到了两个有序链表，那么合并两个有序链表，得到排序后的链表，返回链表头节点。

class Solution
{
    // 876. 链表的中间结点（快慢指针）
    ListNode *middleNode(ListNode *head)
    {
        ListNode *pre = head;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            pre = slow; // 记录 slow 的前一个节点
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr; // 断开 slow 的前一个节点和 slow 的连接
        return slow;
    }

    // 21. 合并两个有序链表（双指针）
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

public:
    ListNode *sortList(ListNode *head)
    {
        // 如果链表为空或者只有一个节点，无需排序
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        // 找到中间节点 head2，并断开 head2 与其前一个节点的连接
        // 比如 head=[4,2,1,3]，那么 middleNode 调用结束后 head=[4,2] head2=[1,3]
        ListNode *head2 = middleNode(head);
        // 分治
        head = sortList(head);
        head2 = sortList(head2);
        // 合并
        return mergeTwoLists(head, head2);
    }
};