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
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *start = dummy;
        for (int i = 0; i < m - 1; i++)
            start = start->next;

        ListNode *cur = start->next;
        for (int i = 0; i < n - m; i++)
        {
            ListNode *Next = cur->next;
            cur->next = Next->next;
            Next->next = start->next;
            start->next = Next;
        }
        return dummy->next;
    }
};