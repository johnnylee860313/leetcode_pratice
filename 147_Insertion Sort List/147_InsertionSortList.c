/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head){
    if(!head)return NULL;
    // create a space of ListNode and make a pointer ,d, point to it
    //d is used to point to a new linklist which stores the old chain listnode in order
    struct ListNode* d = (struct ListNode*)malloc(sizeof(struct ListNode));
    //walk is used to traverse back and forth the new linklist 
    //current point to the old chain and compare with walk
    struct ListNode* walk = d;
    struct ListNode* current = head->next;
    struct ListNode* next = NULL;
    d->next = head;
    d->next->next = NULL;
    printf("hi");
    
    while(current){
        next = current->next;
        while(walk->next && walk->next->val < current->val){
            walk = walk->next;
        }
        current->next = walk->next;
        walk->next = current;

        walk = d;
        current = next;
    }
    return d->next;
    /*struct ListNode* t = head;
    struct ListNode tempt;
    int c=1;
    while(t!=NULL){
        c++;
        t = t->next;
    }
    struct ListNode* a = (struct ListNode*)malloc(c * sizeof(struct ListNode));
    t = head;
    for(int i = 0;i < c;i++){
        a[i] = *t;
        t = t->next;
    }
    // insertion sort
    for(int i = 1;i < c;i++){
        int j = i;
        while(a[j].val < a[j-1].val && j >= 1){
            tempt = a[i];
            a[j] = a[j-1];
            a[j-1] = a[j];
            j--;
        }
    }

    head = &a[0];
    for(int i = 1;i < c;i++){
        head->next = &a[i];
        head = head->next;
    }
    return head;*/
}