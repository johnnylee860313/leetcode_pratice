/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//O(m+n),O(1)
/*
 * listA = A + Common
 * listB =B + Common
 * PointerA: [A + Common + B] + Common
 * PointerB: [B + Common + A] + Common
 * Let a and b walk the same total length then they will must bump to each other at the intersetion
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        
        while(a != b){
            a = a?a->next:headB;
            b = b?b->next:headA;
        }
        return a;
    }
};