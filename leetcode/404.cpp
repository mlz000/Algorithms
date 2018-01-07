/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    long long ans;
    void dfs(TreeNode* rt, int l) {
        if (!rt -> left && !rt -> right) {
            if (l == 1) ans += rt -> val;
            return;
        } 
        if (rt -> left) dfs(rt -> left, 1);
        if (rt -> right)    dfs(rt -> right, 0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)  return 0;
        ans = 0;
        dfs(root, -1);
        return ans;
    }
};