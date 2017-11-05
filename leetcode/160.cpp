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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c0 = 0, c1 = 0;
        ListNode *x = headA, *y = headB;
        while (x) {
            ++c0;
            x = x -> next;
        }
        while (y) {
            ++c1;
            y = y -> next;
        }
        for (int i = c1 - c0; i > 0; --i)   headB = headB -> next;
        for (int i = c0 - c1; i > 0; --i)   headA = headA -> next;
        while (headA) {
            if (headA == headB) return headA;
            headA = headA -> next;
            headB = headB -> next;
        }
        return  NULL;
    }
};