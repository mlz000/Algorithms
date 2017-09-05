const int inf = (1 << 31) - 1;
class Solution {
public:
    void dfs(TreeNode* rt, int &mn, int &mn2) {
        if (!rt)    return;
        if (rt -> val <= mn)    mn = rt -> val;
        else if (rt -> val < mn2)  mn2 = rt -> val;
        dfs(rt -> left, mn, mn2);
        dfs(rt -> right, mn, mn2);
    }
    int findSecondMinimumValue(TreeNode* root) {
        int mn = inf, mn2 = inf;
        dfs(root, mn, mn2);
        if (mn2 == inf) mn2 = -1;
        return mn2;
    }
};