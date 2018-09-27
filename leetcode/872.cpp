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
    vector<int> a1, a2;
    
    void dfs(TreeNode* now, vector<int>& a) {
        if (!now -> left && !now -> right) {
            a.push_back(now -> val);
            return;
        }
        if (now -> left)    dfs(now -> left, a);
        if (now -> right)   dfs(now -> right, a);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1, a1);
        dfs(root2, a2);
        if (a1.size() != a2.size()) return false;
        bool ok = 1;
        for (int i = 0; i < a1.size(); ++i)
            ok &= a1[i] == a2[i];
        return ok;
    }
};
