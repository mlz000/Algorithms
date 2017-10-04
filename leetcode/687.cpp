int ans;
int dfs(TreeNode* rt) {
    if (!rt) {
        return 0;
    }
    int t1 = 0, t2 = 0, t = 0, now = 1;
    if (rt -> left) {
        t1 = dfs(rt -> left);
        if (rt -> left -> val == rt -> val) t = max(t, t1);
        else t1 = 0;
    }
    if (rt -> right) {
        t2 = dfs(rt -> right);
        if (rt -> right -> val == rt -> val)    t = max(t, t2);
        else t2 = 0;
    }
    ans = max(ans, now + t1 + t2);
    now += t;
    return now;
}
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        ans = 1;
        if (!root)  return 0;
        dfs(root);
        return ans - 1;
    }
};