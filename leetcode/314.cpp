/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/
#define pb push_back
#define mp make_pair
class Solution {
public:
    map<int, vector<int> > G;
    vector<vector<int>> verticalOrder(TreeNode* root) {
        G.clear();
        queue<pair<TreeNode*, int> >q;
        vector<vector<int> > ans;
        if (!root)  return ans;
        q.push(mp(root, 0));
        while (q.size()) {
            pair<TreeNode*, int> t = q.front();
            q.pop();
            G[t.second].pb(t.first -> val);
            if (t.first -> left)    q.push(mp(t.first -> left, t.second - 1));
            if (t.first -> right)   q.push(mp(t.first -> right, t.second + 1));
        }
        for (auto& x : G)
            ans.pb(x.second);
        return ans;
    }
};