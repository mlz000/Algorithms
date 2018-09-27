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
    int pos[32];
    TreeNode* dfs(vector<int> &pre, int l1, int r1, vector<int> &post, int l2, int r2) {
        if (l1 > r1)    return nullptr;
        TreeNode* rt = new TreeNode(pre[l1]);
        if (l1 == r1)    return rt;
        int p = pos[pre[l1 + 1]];
        int len = p - l2 + 1;
        rt -> left = dfs(pre, l1 + 1, l1 + len, post, l2, p);
        rt -> right = dfs(pre, l1 + len + 1, r1, post, p + 1, r2 - 1);
        return rt;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        for (int i = 0; i < n; ++i) pos[post[i]] = i;
        return dfs(pre, 0, n - 1, post, 0, n - 1);
    }
};
