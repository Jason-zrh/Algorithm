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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = nullptr;
        ListNode *tail = nullptr;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int carry = 0;
        while (p1 && p2)
        {
            int sum = (p1->val + p2->val + carry) % 10;
            carry = (p1->val + p2->val + carry) / 10;
            ListNode *newNode = new ListNode(sum);
            if (ans == nullptr)
            {
                ans = newNode;
                tail = ans;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        if (p1)
        {
            while (p1)
            {
                int num = (p1->val + carry) % 10;
                carry = (p1->val + carry) / 10;

                ListNode *newNode = new ListNode(num);
                if (ans == nullptr)
                {
                    ans = newNode;
                    tail = ans;
                }
                else
                {
                    tail->next = newNode;
                    tail = newNode;
                }
                p1 = p1->next;
            }
        }

        if (p2)
        {
            while (p2)
            {
                int num = (p2->val + carry) % 10;
                carry = (p2->val + carry) / 10;

                ListNode *newNode = new ListNode(num);
                if (p2 == nullptr)
                {
                    ans = newNode;
                    tail = ans;
                }
                else
                {
                    tail->next = newNode;
                    tail = newNode;
                }
                p2 = p2->next;
            }
        }

        if (carry)
        {
            ListNode *newNode = new ListNode(carry);
            tail->next = newNode;
            tail = newNode;
        }

        return ans;
    }
};