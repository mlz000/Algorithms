/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define eb emplace_back
const int N = 1e5 + 5;
class Solution {
public:
    vector<int> g[N];
    bool vis[N];
    int mx = 0;
    void dfs(TreeNode* root) {
        if (root -> left) {
            g[root -> val].eb(root -> left -> val);
            g[root -> left -> val].eb(root -> val);
            dfs(root -> left);
        }
        if (root -> right) {
            g[root -> val].eb(root -> right -> val);
            g[root -> right -> val].eb(root -> val);     
            dfs(root -> right);
        }
    }
    void dfs2(int now, int fa, int len) {
        mx = max(len, mx);
        for (int i = 0; i < g[now].size(); ++i) {
            if (g[now][i] != fa) {
                dfs2(g[now][i], now, len + 1);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root);
        dfs2(start, 0, 0);
        return mx;
    }
};
