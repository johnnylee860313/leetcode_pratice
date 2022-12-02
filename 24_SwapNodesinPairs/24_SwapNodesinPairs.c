/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head){
    /*struct ListNode* keep;
    struct ListNode* fixedhead;
    fixedhead = head->next;
    while(head && head->next){
        if(head->next->next == NULL){
            keep->next->next=keep;
        }else{
            keep = head->next->next;
            head->next->next = head;
            head->next = keep->next;
            head = keep;
        }
    }
    return fixedhead;
    */
    if(head==NULL||head->next==NULL)return head;
    struct ListNode* t = head->next;
    head->next = swapPairs(head->next->next);
    t->next = head;
    return t;
}
