class Solution {
public:
    TreeNode* dfs(TreeNode* rt, int l, int r) {
        if (!rt)    return NULL;
        if (rt -> val < l) {
            return dfs(rt -> right, l, r);
        }
        else if (rt -> val > r) {
            return dfs(rt -> left, l, r);
        }
        else {
            rt -> left = dfs(rt -> left, l, r);
            rt -> right = dfs(rt -> right, l, r);
        }
        return rt;
    }
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        return dfs(root, L, R);    
    }
};