#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 哈希表简单粗暴
ListNode *detectCycle(ListNode *head)
{
    unordered_map<ListNode *, ListNode *> nodeMap;
    ListNode *l = head;
    while (l != NULL)
    {
        auto it = nodeMap.find(l);
        if (it == nodeMap.end())
            nodeMap[l] = l;
        else
            return it->second;

        l = l->next;
    }
    return NULL;
}

// Floyd判圆法(夯)
ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            while (head != slow)
            {
                head = head->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main()
{

    return 0;
}