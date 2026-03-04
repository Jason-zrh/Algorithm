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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        // 记录头
        ListNode *start = dummy;    
        ListNode *cur = head;
        while (cur)
        {

            // 在组内检查长度够不够
            ListNode *check = cur;
            for (int i = 0; i < k; i++)
            {
                if (!check)
                    return dummy->next;
                check = check->next;
            }
            // 反转
            for (int i = 0; i < k - 1; i++)
            {
                ListNode *Next = cur->next;
                cur->next = Next->next;
                Next->next = start->next;
                start->next = Next;
            }
            // 下一组
            start = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};