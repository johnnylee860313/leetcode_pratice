You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, 
and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

<img width="405" alt="截圖 2022-12-02 下午9 25 23" src="https://user-images.githubusercontent.com/42417212/205302798-17df80a5-ebfd-4b30-a7c6-abf1511d4f0b.png">

1.create a  ListNode struct  tempt and a pointer ,curr, in ListNode type.
2.curr point to tempt,being used to create the result link (curr->next = malloc(sizeof(strucr ListNode))) in while loop
3.while loop 
  3.1 .deal with sum which stores l1 and l2 value,remainder which stores the carry.
  3.2 .create the next node via curr->next = malloc(...)
  3.3 .update l1,l2 if they are not null.
4. return the tempt->next  which is constantly point to the result link.
