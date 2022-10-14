/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> a[15];
    void dfs(TreeNode* rt, int d) {
        if (!rt) {
            return;
        }
        if (d & 1) {
            a[d].emplace_back(rt -> val);
        }
        dfs(rt -> left, d + 1);
        dfs(rt -> right, d + 1);
    }
    void dfs2(TreeNode* rt, int d) {
        if (!rt) {
            return;
        }
        if (d & 1) {
            rt -> val = a[d].back();
            a[d].pop_back();
        }
        dfs2(rt -> left, d + 1);
        dfs2(rt -> right, d + 1);        
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root, 0);
        dfs2(root, 0);
        return root;
    }
};
