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
    int ans;
    int dfs(TreeNode* rt) {
        if (!rt -> left && !rt -> right)  return 1;
        int t1 = 0, t2 = 0;
        if (rt -> left) {
            t1 = dfs(rt -> left);
            if (rt -> val + 1 == rt -> left -> val)  ++t1;
            else t1 = 1;
        }
        if (rt -> right) {
            t2 = dfs(rt -> right);
            if (rt -> val + 1 == rt -> right -> val)   ++t2;
            else t2 = 1;
        }
        ans = max(ans, max(t1, t2));
        return max(t1, t2);
    }
    int longestConsecutive(TreeNode* root) {
        ans = 1;
        if (!root)  return 0;
        dfs(root);
        return ans;
    }
};