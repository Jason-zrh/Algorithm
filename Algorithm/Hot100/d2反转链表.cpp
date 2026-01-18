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


ListNode *reverseList(ListNode *head)
{
    ListNode *newHead = nullptr;  // 新链表的头
    while (head != nullptr)
    {
        ListNode *next = head->next;  // 保存下一个节点
        head->next = newHead;         // 当前节点指向新头
        newHead = head;               // 更新新头为当前节点
        head = next;                  // 前进到下一个节点
    }
    return newHead;
}


int main()
{
    return 0;
}