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
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        if (!pHead1)
            return pHead2;
        if (!pHead2)
            return pHead1;

        ListNode *dummy = new ListNode(0); // 哨兵节点
        ListNode *tail = dummy;

        while (pHead1 && pHead2)
        {
            if (pHead1->val <= pHead2->val)
            {
                tail->next = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                tail->next = pHead2;
                pHead2 = pHead2->next;
            }
            tail = tail->next;
        }

        // 运行到这里，说明其中一个链表已经空了，直接接上剩下的部分
        tail->next = pHead1 ? pHead1 : pHead2;

        return dummy->next;
    }

    ListNode* divideLists(vector<ListNode *> &lists, int left, int right)
    {
        if(left > right)
            return nullptr;
        else if(left == right)
            return lists[left];

        int mid = (left + right) / 2;
        return Merge(divideLists(lists, left, mid), divideLists(lists, mid + 1, right));
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return divideLists(lists, 0, lists.size() - 1);
    }
};