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
    ListNode *ReverseList(ListNode *head)
    {
        ListNode *newHead = nullptr; // 新链表的头
        while (head != nullptr)
        {
            ListNode *next = head->next; // 保存下一个节点
            head->next = newHead;        // 当前节点指向新头
            newHead = head;              // 更新新头为当前节点
            head = next;                 // 前进到下一个节点
        }
        return newHead;
    }

    ListNode *addInList(ListNode *head1, ListNode *head2)
    {
        ListNode *p1 = ReverseList(head1);
        ListNode *p2 = ReverseList(head2);

        ListNode *ans = nullptr;
        ListNode *tail = nullptr;

        int carry = 0;
        while (p1 && p2)
        {
            int sum = p1->val + p2->val + carry;
            carry = sum / 10;
            ListNode *newNode = new ListNode(sum % 10);
            if (ans == nullptr)
                ans = newNode;
            else
                tail->next = newNode;
            tail = newNode;
        }

        if (p1)
        {
            int sum = p1->val + carry;
            carry = sum / 10;
            ListNode *newNode = new ListNode(sum % 10);
            if (ans == nullptr)
                ans = newNode;
            else
                tail->next = newNode;
            tail = newNode;
        }

        if (p2)
        {
            int sum = p2->val + carry;
            carry = sum / 10;
            ListNode *newNode = new ListNode(sum % 10);
            if (ans == nullptr)
                ans = newNode;
            else
                tail->next = newNode;
            tail = newNode;
        }

        if (carry != 0)
        {
            ListNode *newNode = new ListNode(carry);
            if (ans == nullptr)
                ans = newNode;
            else
                tail->next = newNode;
            tail = newNode;
        }

        return ReverseList(ans);
    }
};
