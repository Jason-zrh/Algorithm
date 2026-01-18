#include <iostream>
#include <unordered_map>
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

// 哈希表(拉完了)
bool isPalindrome(ListNode *head)
{
    unordered_map<int, ListNode *> nodeMap;
    int count = 0;
    ListNode *tail = head;
    // 把下标与节点对应
    while (tail != nullptr)
    {
        nodeMap[count] = tail;
        count++;
        tail = tail->next;
    }
    int left = 0, right = count - 1;
    while (left < right)
    {
        if (nodeMap[left]->val != nodeMap[right]->val)
            return false;

        left++;
        right--;
    }
    return true;
}

// 数组(NPC)
bool isPalindrome(ListNode *head)
{
    ListNode *tail = head;
    vector<ListNode *> nodes;
    int cnt = 0;
    while (tail != nullptr)
    {
        nodes.push_back(tail);
        tail = tail->next;
        cnt++;
    }
    int left = 0, right = cnt - 1;
    while (left < right)
    {
        if (nodes[left]->val != nodes[right]->val)
            return false;

        left++;
        right--;
    }
    return true;
}


// 快慢指针找中点反转(夯)
class Solution
{
public:
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
    bool isPalindrome(ListNode *head)
    {
        // 先快慢指针找到尾和中点
        ListNode *slow = head;
        ListNode *fast = head;
        int cnt = 0;
        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
            cnt++;
            if (fast == nullptr)
                break;
            else
            {
                fast = fast->next;
                cnt++;
            }
        }
        // 这里慢指针指向的是应该开始反转的地方
        slow = reverseList(slow);

        ListNode *h = head;
        ListNode *t = slow;
        while (t != nullptr)
        {
            if (h->val != t->val)
                return false;
            h = h->next;
            t = t->next;
        }
        return true;
    }
};

int main()
{

    return 0;
}