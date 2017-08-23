class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> f;
    unordered_map<TreeNode*, int> dep;
    void dfs(TreeNode* rt, int d) {
        dep[rt] = d;
        if (rt -> left)    f[rt -> left] = rt, dfs(rt -> left, d + 1);
        if (rt -> right)   f[rt -> right] = rt, dfs(rt -> right, d + 1);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, 0);
        if (dep[p] > dep[q])    swap(p, q);
        while (dep[p] != dep[q])    q = f[q];
        while (p != q)  p = f[p], q = f[q];
        return p;
    }
};
