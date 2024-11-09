/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//O(n),O(1)
/** 
 *  2 1 3 5 6 4 7
 *  2 3 1 5 6 4 7
 *  2 3 6 1 5 4 7
 *  ....
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)return head;
        
        ListNode *pre = head;
        ListNode *cur = head->next;
        
        while(cur && cur->next){
            ListNode *tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
            pre = pre->next;
            cur = cur->next;
        }
        return head;
    }
};
