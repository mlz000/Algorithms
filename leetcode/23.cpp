/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define mp make_pair
class Solution {
public:
    priority_queue<pair<int, ListNode*> >pq;
    ListNode* mergeKLists(vector<ListNode*>& a) {
        int n = a.size();
        for (int i = 0; i < n; ++i)
            if (a[i]) pq.push(mp(-a[i] -> val, a[i]));
        ListNode* head = new ListNode(-1), *now = new ListNode(-1);
        head -> next = now;
        while(pq.size()) {
            pair<int, ListNode*> t = pq.top();
            pq.pop();
            ListNode* tmp = new ListNode(-t.first);
            now -> next = tmp;
            now = now -> next;
            if (t.second -> next)   pq.push(mp(-t.second -> next -> val, t.second -> next));
        }
        return head -> next -> next;
    }
};