struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseKGroup(ListNode *head, int k)
{
    // 哨兵头节点
    ListNode dummy(0, head);
    ListNode* node0 = &dummy;
    // 用来遍历链表的指针节点
    ListNode* it = node0->next;
    // 尾节点
    ListNode* tail = node0;
    // it要存在
    while(it)
    {
        int flag = 0; // 标志这一组长度是否足够k

        // 翻转一组链表
        ListNode* tmp = nullptr;
        ListNode* newtail = nullptr;
        // 保存起点
        ListNode* start = it;
        for(int i = 0; i < k; i++)
        {
            // 遍历到链表结尾
            if(it == nullptr)
            {
                flag = 1;
                break; 
            }
            ListNode* newNode = new ListNode(it->val);
            if(tmp == nullptr) // 翻转链表为空
            {
                tmp = newNode;
                tmp->next = nullptr;
                newtail = tmp; // 保存新的尾节点
                it = it->next; // 迭代
                continue;
            }
            // 翻转链表不为空
            newNode->next = tmp;
            tmp = newNode;
            // 向后迭代
            it = it->next;
        }

        // 链表长度不足，保存原有顺序
        if(flag)
        {
            tail->next = start;
            break;
        }
        // it向后移动k次指向下一次翻转的开头
        tail->next = tmp;
        tail = newtail; // 更新尾
    }
    return dummy.next;
}