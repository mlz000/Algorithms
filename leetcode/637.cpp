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
    vector<pair<int, long long> > a;
    vector<double> ans;
    void dfs(TreeNode* rt, int dep) {
        if (dep >= a.size()) {
            a.push_back(make_pair(1, rt -> val));
        }
        else a[dep].first++, a[dep].second += rt -> val;
        if (rt -> left) dfs(rt -> left, dep + 1);
        if (rt -> right)    dfs(rt -> right, dep + 1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root)  return ans;
        dfs(root, 0);
        for (int i = 0; i < a.size(); ++i)
            ans.push_back((double)a[i].second / a[i].first);
        return ans;
    }
};