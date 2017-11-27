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
private:
    int ans;
public:
    int dfs(TreeNode* rt) {
        if (!rt)    return 0;
        int t1 = 0, t2 = 0;
        t1 = max(t1, dfs(rt -> left));
        t2 = max(t2, dfs(rt -> right));
        ans = max(ans, t1 + t2 + rt -> val);
        return max(t1, t2) + rt -> val;
    }
    int maxPathSum(TreeNode* root) {
        ans = -1e9;
        dfs(root);
        return ans;
    }
};