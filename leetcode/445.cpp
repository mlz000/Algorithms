/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define pb push_back
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> a, b, c;
        while (l1) {
            a.pb(l1 -> val);
            l1 = l1 -> next;
        }
        while (l2) {
            b.pb(l2 -> val);
            l2 = l2 -> next;
        }
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        ListNode* head = NULL, *now = NULL;
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += a[i--];
            if (j >= 0) sum += b[j--];
            carry = sum / 10;
            now = new ListNode(sum % 10);
            now -> next = head;
            head = now;
        }
        return head;
    }
};