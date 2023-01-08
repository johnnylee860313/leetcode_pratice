/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* findMiddle(struct ListNode*);
struct ListNode* mergeTwo(struct ListNode*,struct ListNode*);

struct ListNode* sortList(struct ListNode* head){
    //if List is a single node or NULL
    if(head == NULL || head->next == NULL)return head;

    //find the middle node
    struct ListNode* mid = findMiddle(head);

    //split the list to two half list
    struct ListNode* t = head;
    struct ListNode* cut = NULL;
    while(t != mid){
        cut = t;
        t = t->next;
    }
    cut->next = NULL;

    //recursively split the list until to single node
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(mid);

    //then bottom up merge any two list
    return mergeTwo(left,right);
}

struct ListNode* findMiddle(struct ListNode* head){
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct ListNode* mergeTwo(struct ListNode* left,struct ListNode* right){
    struct ListNode* newhead = NULL;//pointer to the new head,with the smallest node value
    struct ListNode* tempt = NULL;
    //choose the new head
    if(left->val < right->val){
        newhead = left;
        left = left->next;
    }else{
        newhead = right;
        right = right->next;
    }

    tempt = newhead;
    while(left && right){//merge two list
        if(left->val < right->val){
            tempt->next = left;
            left = left->next;
        }else{
            tempt->next = right;
            right = right->next;
        }
        tempt = tempt->next;    
    }
    //deal with the bottom situation which means only two nodes in comparison
    if(left){
        tempt->next = left;
        tempt = tempt->next;
    }
    if(right){
        tempt->next = right;
        tempt = tempt->next;
    }

    return newhead; 
}