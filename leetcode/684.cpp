/*
We are given a "tree" in the form of a 2D-array, with distinct values for each node.

In the given 2D-array, each element pair [u, v] represents that v is a child of u in the tree.

We can remove exactly one redundant pair in this "tree" to make the result a tree.

You need to find and output such a pair. If there are multiple answers for this question, output the one appearing last in the 2D-array. There is always at least one answer.
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
*/
int f[2001];
class Solution {
public:
    int find(int x) {
        return f[x] == x ? f[x] : f[x] = find(f[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int i = 1; i <= 2000; ++i) f[i] = i;
        for (auto& e : edges) {
            int fa = find(e[0]), fb = find(e[1]);
            if (fa == fb)   return e;
            f[fb] = fa;
        }
    }
};