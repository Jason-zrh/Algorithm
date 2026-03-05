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


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead1 ListNode类 
     * @param pHead2 ListNode类 
     * @return ListNode类
     */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* ans = nullptr;
        ListNode* tail = nullptr;

        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;

        while(p1 && p2)
        {
            ListNode* newNode = new ListNode(0);
            if(p1->val > p2->val)
            {
                newNode->val = p2->val;
                p2 = p2->next;
            }
            else
            {
                newNode->val = p1->val;
                p1 = p1->next;
            }

            if(ans == nullptr)
                ans = newNode;
            else    
                tail->next = newNode;
            
            tail = newNode;
        }

        if(p1)
        {
            if(ans == nullptr)
                return p1;
            else
                tail->next = p1;
        }

        if(p2)
        {
            if(ans == nullptr)
                return p2;
            else
                tail->next = p2;
        }

        return ans;
    }
};