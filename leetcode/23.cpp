/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l -> val > r -> val;
    }
};
class Solution {
public:
    priority_queue<ListNode*, vector<ListNode*>, cmp >pq;
    ListNode* mergeKLists(vector<ListNode*>& a) {
        int n = a.size();
        for (int i = 0; i < n; ++i)
            if (a[i]) pq.push(a[i]);
        if (!pq.size())  return NULL;
        ListNode* head = pq.top();
        pq.pop();
        if (head -> next)   pq.push(head -> next);
        ListNode *now = head;
        while(pq.size()) {
            now -> next = pq.top();
            pq.pop();
            now = now -> next;
            if (now -> next)    pq.push(now -> next);
        }
        return head;
    }
};