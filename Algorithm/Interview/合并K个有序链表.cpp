#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(ListNode* head1, ListNode* head2)   
    {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(head1 && head2)
        {
            if(head1->val < head2->val)
            {
                tail->next = head1;
                head1 = head1->next;
            }
            else
            {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }
        tail->next = head1 ? head1 : head2;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists, int l, int r)
    {
        int n = r - l;
        if(n == 0)
            return nullptr;
        if(n == 1)
            return lists[l];
        
        ListNode* left = mergeKLists(lists, l, (l + r) / 2);
        ListNode* right = mergeKLists(lists, (l + r) / 2, r);
        return merge(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int left = 0, right = lists.size();
        return mergeKLists(lists, left, right);
    }
};