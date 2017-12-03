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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode* head = root;
        int cnt = 0;
        vector<ListNode*> ans;
        while (head) {
            ++cnt;
            head = head -> next;
        }
        int a = cnt / k, b = cnt % k;
        head = root;
        for (int i = 1; i <= k; ++i) {
            int now = a + (i <= b);
            if (now == 0)   ans.push_back(NULL); 
            else {
                ListNode* tmp = head;
                for (int j = 1; j < now; ++j)   head = head -> next;
                ListNode* t = head -> next;
                head -> next = NULL;
                head = t;
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};