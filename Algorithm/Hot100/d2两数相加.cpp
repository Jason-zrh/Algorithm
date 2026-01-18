#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *list1 = l1;
    ListNode *list2 = l2;

    ListNode *ret = nullptr;
    ListNode *tail = nullptr;

    int carry = 0;
    while (list1 && list2)
    {
        int num = list1->val + list2->val + carry;
        if (num > 9)
        {
            carry = 1;
            num -= 10;
        }
        else
            carry = 0;

        ListNode *newNode = new ListNode(num);
        if (ret == nullptr)
        {
            ret = newNode;
            tail = ret;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        list1 = list1->next;
        list2 = list2->next;
    }

    if (list1 != nullptr)
    {
        while (list1)
        {
            int num = list1->val + carry;
            if (num > 9)
            {
                carry = 1;
                num -= 10;
            }
            else
                carry = 0;

            ListNode *newNode = new ListNode(num);
            if (ret == nullptr)
            {
                ret = newNode;
                tail = ret;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            list1 = list1->next;
        }
    }
    if (list2 != nullptr)
    {
        while (list2)
        {
            int num = list2->val + carry;
            if (num > 9)
            {
                carry = 1;
                num -= 10;
            }
            else
                carry = 0;

            ListNode* newNode = new ListNode(num);
            if (ret == nullptr)
            {
                ret = newNode;
                tail = ret;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            list2 = list2->next;
        }
    }

    if (carry)
    {
        ListNode *newNode = new ListNode(carry);
        tail->next = newNode;
        tail = newNode;
    }
    return ret;
}

int main()
{

    return 0;
}