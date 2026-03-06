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
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode *oddEvenList(ListNode *head)
    {
        if(head == nullptr)
            return nullptr;
        int pos = 1;
        ListNode* even = nullptr;
        ListNode* tail = nullptr;

        ListNode* cur = head;
        ListNode* prev = head;

        while (cur)
        {
            if(pos % 2 != 0)
            {
                prev = cur;
                cur = cur->next;
                pos++;
            }
            else
            {
                // 偶数节点
                prev->next = cur->next;
                ListNode* newNode = new ListNode(cur->val);
                if(even == nullptr)
                    even = newNode;
                else
                    tail->next = newNode;
                tail = newNode;
                cur = cur->next;
                pos++;
            }
        }

        prev->next = even;
        return head;
    }
};