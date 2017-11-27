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
class Solution {
private:
    stack<TreeNode*> l, r;
    vector<int> ans;
public:
    void left() {
        TreeNode* now = l.top();
        l.pop();
        if (now -> left) {
            now = now -> left;
            while (now) {
                l.push(now);
                now = now -> right;
            }
        }
    }
    void right() {
        TreeNode* now = r.top();
        r.pop();
        if (now -> right) {
            now = now -> right;
            while (now) {
                r.push(now);
                now = now -> left;
            }
        }
    }
    void init(TreeNode* rt, double target) {
        while (rt) {
            if (rt -> val <= target) {
                l.push(rt);
                rt = rt -> right;
            }
            else r.push(rt), rt = rt -> left;
        }
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        ans.clear();
        while (l.size())    l.pop();
        while (r.size())    r.pop();
        init(root, target);
        while (k--) {
            if (!r.size() || (l.size() && fabs(target - l.top() -> val) <= fabs(target - r.top() -> val))) {
                ans.pb(l.top() -> val);
                left();
            }
            else ans.pb(r.top() -> val), right();
        }
        return ans;
    }
};