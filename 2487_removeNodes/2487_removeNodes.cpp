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
// class Solution {//放到st裡再串起來
// public:
//     ListNode *removeNodes(ListNode *head) {
//         stack<ListNode *> st;
//         for (ListNode *it = head; it != nullptr; it = it->next) {
//             while (!st.empty() && st.top()->val < it->val) {
//                 ListNode *x = st.top();
//                 st.pop();
//             }
//             st.push(it);
//         }

//         ListNode *dummy = new ListNode(), *curr = dummy;
//         while (!st.empty()) {
//             st.top()->next = nullptr;
//             curr->next = st.top();
//             curr = curr->next;
//             st.pop();
//         }
//         curr = dummy->next;

//         // Reverse the linked list.
//         ListNode *newHead = nullptr;
//         while (curr != nullptr) {
//             ListNode *x = curr->next;
//             curr->next = newHead;
//             newHead = curr;
//             curr = x;
//         }

//         return newHead;
//     }
// };


class Solution { //reverse once and remove the smaller, then reverse again
public:
    ListNode* ReverseList(ListNode *head) {
        if (!head)
            return nullptr;
        ListNode *last = head, *now = head->next, *next;
        while (now) {
            next = now->next;
            now->next = last;
            last = now;
            now = next;
        }
        head->next = nullptr;
        return last;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode *nowTail, *nowNode;
        nowNode = nowTail = head = ReverseList(head);
        while (nowNode->next) {
            nowNode = nowNode->next;
            if (nowTail->val <= nowNode->val) {
                nowTail->next = nowNode;
                nowTail = nowNode;
            }
        }
        nowTail->next = nullptr;
        return ReverseList(head);
    }
};
// class Solution { //recurrsive
//  public:
//   ListNode* removeNodes(ListNode* head) {
//     if (head == nullptr)
//       return nullptr;
//     head->next = removeNodes(head->next);
//     return head->next != nullptr && head->val < head->next->val ? head->next : head;
//   }
// };