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
    int now;
    int dfs(TreeNode* rt) {
        if (!rt)    return 0;
        int t1 = dfs(rt -> left);
        int t2 = dfs(rt -> right);
        now = max(now, t1 + t2 + 1);
        return max(t1, t2) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)  return 0;
        dfs(root);
        return now - 1;
    }
};