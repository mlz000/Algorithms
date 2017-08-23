class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int l = 1;
        ListNode *now, *tail;
        now = tail = head;
        while(tail -> next) {
            tail = tail -> next;
            ++l;
        }
        tail -> next = head;
        if(k %= l) {
            for(auto i = 0; i < l - k; ++i) tail = tail -> next;
        }
        now = tail -> next; 
        tail -> next = NULL;
        return now;
    }
};