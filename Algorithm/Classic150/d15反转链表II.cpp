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
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        // 设置哨兵节点，处理 left = 1 的特殊情况
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // 1. 找到待反转区间的前驱节点 pre
        ListNode *pre = dummy;
        for (int i = 0; i < left - 1; i++)
        {
            pre = pre->next;
        }

        // 2. 开始局部反转
        // cur 是我们要反转的区间的第一个节点
        ListNode *cur = pre->next;
        for (int i = 0; i < right - left; i++)
        {
            // next 是 cur 的下一个节点，我们要把它提到 pre 的后面
            ListNode *Next = cur->next;

            cur->next = Next->next; // cur 连接到下下个
            Next->next = pre->next; // next 指向当前区间的头部
            pre->next = Next;       // pre 指向新的头部
        }

        return dummy->next;
    }
};