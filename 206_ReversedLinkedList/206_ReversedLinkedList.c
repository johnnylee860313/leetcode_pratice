/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *pre = NULL;
    struct ListNode *next = NULL;

    if(!head)return NULL;

    while(head){
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}
