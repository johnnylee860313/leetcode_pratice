/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* merg(struct ListNode**,int,int);
struct ListNode* merge_two_lists(struct ListNode*,struct ListNode*);

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
   return  merg(lists,0,listsSize-1);
}

struct ListNode* merg(struct ListNode** lists,int begin,int end){
    if(begin > end)return NULL;
    if(begin == end)return lists[begin];

    struct ListNode* left = merg(lists,begin,(begin+end)/2);
    struct ListNode* right = merg(lists,((begin+end)/2)+1,end);

    return merge_two_lists(left,right);
}

struct ListNode* merge_two_lists(struct ListNode* list1,struct ListNode* list2){
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = dummy;

    if(list1==NULL)return list2;
    if(list2==NULL)return list1;
    while(list1 && list2){
        if(list1->val < list2->val){
            current->next = list1;
            list1 = list1->next;
        }else{
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    if(list1) current->next = list1;
    if(list2) current->next = list2;

    current = dummy->next;
    free(dummy);
    return current;
}