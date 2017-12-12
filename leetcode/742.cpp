/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define pb push_back
class Solution {
public:
    vector<int> g[1005];
    int ans, res;
    bool leaf[1005];
    void dfs(TreeNode *root) {
        if (!root)  return ;
        if (root -> left) {
            g[root -> left -> val].pb(root -> val);
            g[root -> val].push_back(root -> left -> val);
            dfs(root -> left);
        }
        if (root -> right) {
            g[root -> right -> val].pb(root -> val);
            g[root -> val].push_back(root -> right -> val);
            dfs(root -> right);
        }
        if (!root -> left && !root -> right)    leaf[root -> val] = 1;
    }
    void dfs2(int u, int fa, int dep) {
        if (leaf[u]) {
            if (dep < ans) {
                ans = dep;
                res = u;
                return;
            }
        }
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            if (v == fa)    continue;
            dfs2(v, u, dep + 1);
        }
    }
    int findClosestLeaf(TreeNode* root, int k) {
        if (!root -> left && !root -> right)    return root -> val;
        for (int i = 1; i <= 1000; ++i) g[i].clear();
        memset(leaf, 0, sizeof(leaf));
        dfs(root);
        ans = 10000;
        dfs2(k, 0, 0);
        return res;
    }
};