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
    ListNode* reverseList(ListNode* head) {
        ListNode* last = NULL;
        while (head) {
            ListNode* now = head -> next;
            head -> next = last;
            last = head;
            head = now;
        }
        return last;
    }
};