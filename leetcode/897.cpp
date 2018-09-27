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
    void dfs(TreeNode *rt, vector<int> &a) {
        if (!rt)    return;
        dfs(rt -> right, a);
        a.push_back(rt -> val);
        dfs(rt -> left, a);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> a;
        dfs(root, a);
        TreeNode* last = nullptr;
        for (auto x: a) {
            TreeNode *now = new TreeNode(x);
            now -> right = last;
            now -> left = nullptr;
            last = now;
        }
        return last;
    }
};
