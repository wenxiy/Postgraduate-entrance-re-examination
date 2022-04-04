/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    /**直接遍历单链表然后删除
    官方题解真的很烂，没有free没有malloc的分配指针指向，所以这几点一定要注意
    这个题大概就是最重要的是自己定义一个头节点，说实话官方的题说的也不清楚，有没有头节点没说清楚，其实没有头节点自己也能做就是麻烦点
    然后判断的时候一定要判断清楚是头节点dummyhead = NULL 还是 ->next == NULL
    **/
    struct ListNode *dummyhead = malloc(sizeof(struct ListNode));
    dummyhead->next = head;
    if (dummyhead->next == NULL){
        return head;
    }
    struct ListNode *p = dummyhead;
    while (p->next != NULL){
        if (p->next->val == val){
           struct ListNode *d = p->next;
           p->next = p->next->next;
            free(d);
        }
        else{
            p = p->next;
        }
    }
    return dummyhead->next;
}