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
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) return head;
        int n = 0;
        for (ListNode* p = head; p; p = p -> next)  ++n;
        n /= 2;
        ListNode* ans = head;
        while (n > 0) {
            ans = ans -> next;
            --n;
        }
        return ans;
    }
};
