#define lt RandomListNode
class Solution {
public:
    unordered_map<lt*, lt*> G;
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)  return NULL;
        if (G.find(head) != G.end())    return G[head];
        lt* now = new lt(head -> label);
        G[head] = now;
        now -> next = copyRandomList(head -> next);
        now -> random = copyRandomList(head -> random);
        return now;
    }
};