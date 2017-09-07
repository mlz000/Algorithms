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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while (l1 && l2) {
            if (l1 -> val < l2 -> val) {
                head -> next = l1;
                l1 = l1 -> next;
            }
            else {
                head -> next = l2;
                l2 = l2 -> next;
            }
            head = head -> next;
        }
        if (l1) head -> next = l1;
        if (l2) head -> next = l2;
        return dummy -> next;
    }
};