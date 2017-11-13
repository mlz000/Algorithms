/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define mp make_pair
#define F first
#define S second
typedef pair<int, int> pii;
class Solution {
public:
    bool ok;
    pii dfs(TreeNode* rt) {
        if (!rt -> right && !rt -> left)     {
            return mp(rt -> val, rt -> val);
        }
        pii t = mp(rt -> val, rt -> val);
        if (rt -> left) {
            pii t1 = dfs(rt -> left);
            if (t1.S >= rt -> val)  ok = 0;
            t.F = min(t.F, t1.F);
            t.S = max(t.S, t1.S);
        }
        if (rt -> right) {
            pii t2 = dfs(rt -> right);
            if (t2.F <= rt -> val)  ok = 0;
            t.F = min(t.F, t2.F);
            t.S = max(t.S, t2.S);
        }
        return t;
    }
    bool isValidBST(TreeNode* root) {
        if (!root)  return 1;
        ok = 1;
        dfs(root);
        return ok;
    }
};
