#define pb push_back
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*> > G;
        vector<TreeNode*> ans;
        dfs(root, G);
        for (auto it : G)
            if (it.second.size() > 1)  
                ans.pb(it.second[0]);
        return ans;
    }

private:
    string dfs(TreeNode* node, unordered_map<string, vector<TreeNode*> > &G) {
        if (!node) return "";
        string s = "(" + dfs(node -> left, G) + to_string(node -> val) + dfs(node -> right, G) + ")";
        G[s].pb(node);
        return s;
    }
};