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

ListNode *reverseList(ListNode *head)
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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode* newNode = reverseList(head);
    ListNode* pos = newNode;
    ListNode* prev = nullptr;
    for(int i = 0; i < n - 1; i++)
    {
        prev = pos;
        pos = pos->next;
    }
    if(!prev) // 没进入循环删的是倒数第一个
    {
        if(!pos->next) // 链表长度就是1
            return nullptr;
        return reverseList(pos->next);
    }
    // 删除的正好是第一个
    if(!pos->next)
        prev->next = nullptr;
    else
        prev->next = pos->next;
    
    return reverseList(newNode);
}