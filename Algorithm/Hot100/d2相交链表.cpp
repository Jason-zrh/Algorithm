#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 双指针
// 注意: 相交链表不是单纯的值相等，而是要指向的地址相同
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // 如果两个链有一个为空
    if (headA == NULL || headB == NULL)
        return NULL;

    // 两链均不为空, 计算一下两链长度，从最长的开始找
    ListNode *a = headA;
    int lenA = 0;
    while (a != NULL)
    {
        a = a->next;
        lenA++;
    }
    ListNode *b = headB;
    int lenB = 0;
    while (b != NULL)
    {
        b = b->next;
        lenB++;
    }

    // 两链交替查找，每次减少的是长度长的那条链
    ListNode *A = headA;
    ListNode *B = headB;
    while (lenA && lenB)
    {
        if (A != B)
        {
            // 减去长度最长的那个链，如果相等就随便减一个
            if (lenA > lenB)
            {
                lenA--;
                A = A->next;
            }
            else
            {
                lenB--;
                B = B->next;
            }
        }
        else
            return A;
    }
    return NULL;
}

// 哈希表
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    unordered_map<ListNode *, ListNode *> nodeMap;
    ListNode *A = headA;
    while (A != NULL)
    {
        nodeMap[A] = A;
        A = A->next;
    }

    ListNode *B = headB;
    while (B != NULL)
    {
        auto it = nodeMap.find(B);
        if (it == nodeMap.end())
        {
            // 在哈希表中没有
            B = B->next;
        }
        else
            return it->second;
    }
    return NULL;
}