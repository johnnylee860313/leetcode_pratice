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
//know the linkedlist length first
//connect the head and the tail
//move the head to sz - k
//then break the cycle from the tail
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        int sz = 1;
        ListNode *cur = head;
        while (cur->next) {
            ++sz;
            cur = cur->next;
        }
        cur->next = head;//make it cycle
        //move head to new head
        int m = sz - k % sz;
        for (int i = 0; i < m; ++i) {
            cur = cur->next;
        }
        ListNode *newhead = cur->next;
        cur->next = NULL;
        return newhead;
    }
};