/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       if (!head)  return NULL;
       ListNode *now = head;
       for (int i = 0; i < k; ++i) {
           if (now == NULL) return head;
           now = now -> next;
       }
       ListNode *last = NULL, *t = head;
       for (int i = 0; i < k; ++i) {
           ListNode* tmp = t -> next;
           t -> next = last;
           last = t;
           t = tmp;
       }
       head -> next = reverseKGroup(now, k);
       return last; 
    }
};