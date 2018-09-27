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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        if (n == 1) {
            TreeNode* rt = new TreeNode(0);
            ans.push_back(rt);
            return ans;
        }
        
        if (n % 2 == 0 || n < 1)  return ans;
        for (int i = 1; i < n; i += 2) {
            auto l = allPossibleFBT(i);
            auto r = allPossibleFBT(n - i - 1);
            for (int j = 0; j < l.size(); ++j)
                for (int k = 0; k < r.size(); ++k) {
                    TreeNode* rt = new TreeNode(0);
                    rt -> left = l[j];
                    rt -> right = r[k];
                    ans.push_back(rt);
                }
        }
        return ans;
    }    
};
