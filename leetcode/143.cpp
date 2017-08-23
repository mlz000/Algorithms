#define node ListNode 
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head -> next) return;
        node* t1 = head, *t2 = head -> next;
        while (t2 && t2 -> next) {
            t1 = t1 -> next;
            t2 = t2 -> next -> next;
        }
        node* head2 = t1 -> next;
        t1 -> next = NULL;
        t2 = head2 -> next, head2 -> next = NULL;
        while (t2) {
            t1 = t2 -> next;
            t2 -> next = head2;
            head2 = t2;
            t2 = t1;
        }
        t1 = head, t2 = head2;
        while (t1) {
            auto t = t1 -> next;
            t1 = t1 -> next = t2;
            t2 = t;
        }
    }
};