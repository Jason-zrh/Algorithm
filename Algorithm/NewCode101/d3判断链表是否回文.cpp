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
     * @param head ListNode类 the head
     * @return bool布尔型
     */
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

        pre->next = nullptr;
        return slow;
    }   

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

    bool isPail(ListNode *head)
    {
        ListNode* head2 = findMiddle(head);

        ListNode* newhead = ReverseList(head2);

        ListNode* p1 = head;
        ListNode* p2 = newhead;
        while (p1)
        {
            if(p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};