/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define pb push_back
vector<vector<int> > ans;
void dfs(TreeNode* rt, int dep) {
    if (!rt)    return;
    if (ans.size() <= dep)   ans.pb(vector<int>());
    ans[dep].pb(rt -> val);
    dfs(rt -> left, dep + 1);
    dfs(rt -> right, dep + 1);
}
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        ans.clear();
        dfs(root, 0);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};