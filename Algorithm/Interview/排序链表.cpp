#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // 断开原链表与中间节点的联系
        pre->next = nullptr;
        return slow;
    }

    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        while (head1 && head2)
        {
            if (head1->val > head2->val)
            {
                tail->next = head2;
                head2 = head2->next;
            }
            else
            {
                tail->next = head1;
                head1 = head1->next;
            }
            tail = tail->next;
        }
        tail->next = head1 ? head1 : head2;
        return dummy->next;
    }
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *head2 = middleNode(head);
        head = sortList(head);
        head2 = sortList(head2);
        return merge(head, head2);
    }
};