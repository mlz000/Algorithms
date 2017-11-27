class Solution {
public:
    int ans;
    int dfs(TreeNode* rt) {
        if (!rt)    return 0;
        int a = dfs(rt -> left);
        int b = dfs(rt -> right);
        int t = 0, t2 = 0;
        if (rt -> left && rt -> val == rt -> left -> val) t += a + 1, t2 =  a + 1;
        if (rt -> right && rt -> val == rt -> right -> val)    t += b + 1, t2 = max(t2, b + 1);
        ans = max(ans, t);
        return t2;
    }
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};