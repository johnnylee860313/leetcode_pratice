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
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count = 1;
        int rem  = 0;
        vector<ListNode*> res;
        ListNode* tempt = head;
        ListNode* curr = head;

        if(head==NULL){
            for(int i = 0;i < k;++i){
                res.push_back({});
            }
            return res;
        }

        while(tempt->next){
            count++;
            tempt = tempt->next;
        }
    
        rem = count%k;

        while(curr){
            int sub = 0;
            res.push_back(curr);

            if(rem > 0){
                sub = count/k + 1;
                rem--;
            }else{
                sub = count/k;
            }

            for(int i = 0;i < sub;++i){
                if(i == sub-1)tempt=curr;
                curr = curr->next;
            }
            tempt->next = NULL;
        }

        if(k > count){
            for(int i = 0;i < k-count;++i){
                res.push_back({});
            }
        }
        return res;
    }
};