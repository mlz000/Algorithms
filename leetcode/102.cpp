#define pb push_back
class Solution {
    vector< vector<int> > ret;
    void dfs(TreeNode* root, int dep) {
        if (!root) return ;
        if (ret.size() <= dep) ret.pb(vector<int>());
        ret[dep].pb(root -> val);
        dfs(root -> left, dep + 1); 
        dfs(root -> right, dep + 1);   
        return ;
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return ret;
    }
};
