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
    bool isPalindrome(ListNode* head) {
        if (!head || !head -> next) return 1;
        ListNode* slow = head, *fast = head -> next;
        int cnt = 1;
        while (fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            ++cnt;
        }
        ListNode* head2 = slow -> next, *last = NULL;
        while (head2) {
            ListNode* tmp = head2 -> next;
            head2 -> next = last;
            last = head2;
            head2 = tmp;
        }
        head2 = last;
        while (cnt--) {
            if (head -> val == head2 -> val) {
                head = head -> next;
                head2 = head2 -> next;
            }
            else return 0;
        }
        return 1;
    }
};