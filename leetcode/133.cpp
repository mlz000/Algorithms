class Solution {
public:
    map<UndirectedGraphNode *, UndirectedGraphNode *> m;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)    return NULL;
        if(m.find(node) != m.end()) return m[node];
        UndirectedGraphNode *t = new UndirectedGraphNode(node -> label);
        m[node] = t;
        for(auto x : node -> neighbors) {
            UndirectedGraphNode *temp = cloneGraph(x);
            if(temp != NULL)    t -> neighbors.push_back(temp);
        }
        return t;
    }
};