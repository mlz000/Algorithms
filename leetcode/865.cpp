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
    int mx, cnt, ansdep;
    TreeNode* ans;
    void dfs(TreeNode* root, int dep) {
        if (!root)  return;
        if (dep > mx) {
            mx = dep;
            cnt = 1;
        }
        else if (dep == mx) ++cnt;
        dfs(root -> left, dep + 1);
        dfs(root -> right, dep + 1);
    }
    int calc(TreeNode* root, int dep) {    
        if (!root)  return 0;
        int now;
        if (!root -> left && !root -> right)   now = (dep == mx);
        else now = calc(root -> left, dep + 1) + calc(root -> right, dep + 1);
        if (now == cnt) {
            if (dep >= ansdep) {
                ans = root;
                ansdep = dep;
            }
        }
        return now;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        mx = cnt = ansdep = 0;
        dfs(root, 0);
        calc(root, 0);
        return ans;
    }
};
