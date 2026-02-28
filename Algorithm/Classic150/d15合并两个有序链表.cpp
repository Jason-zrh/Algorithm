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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* ans = nullptr;
        ListNode* tail = nullptr;
        while(p1 && p2)
        {
            if(p1->val < p2->val)
            {
                if(ans == nullptr)
                {
                    ans = p1;
                    tail = p1;
                }
                else
                {
                    tail->next = p1;
                    tail = p1;
                }
                p1 = p1->next;
            }
            else
            {
                if(ans == nullptr)
                {
                    ans = p2;
                    tail = p2;
                }
                else
                {
                    tail->next = p2;
                    tail = p2;
                }
                p2 = p2->next;
            }
        }

        if(p1)
        {
            if(ans == nullptr)
            {
                ans = p1;
                tail = p1;
            }
            else
            {
                tail->next = p1;
                tail = p1;
            }
        }
        

        
        if(p2)
        {
            if(ans == nullptr)
            {
                ans = p2;
                tail = p2;
            }
            else
            {
                tail->next = p2;
                tail = p2;
            }
        }


        return ans;
    }
};