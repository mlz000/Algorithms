/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Node {
    stack<TreeNode*> s;
    TreeNode* node;
    bool L;
    Node(TreeNode* node, bool L): node(node), L(L){};
    void left(TreeNode *t) {
        while (t) {
            s.push(t);
            t = t -> left;
        }
    }
    void right(TreeNode *t) {
        while (t) {
            s.push(t);
            t = t -> right;
        }
    }
    int next() {
        if (s.size()) {
            TreeNode* now = s.top();
            s.pop();
            if (L && now -> right)   left(now -> right);
            if (!L && now -> left)   right(now -> left);
            return now -> val;
        }
        if (L)  return 1e9;
        else return -1e9;
    }
};
class Solution {
private:
    stack<TreeNode> s1, s2;
public:
    
    bool findTarget(TreeNode* root, int k) {
        Node l(root, 1), r(root, 0);
        l.left(root), r.right(root);
        for (int i = l.next(), j = r.next(); i < j; ) {
            if (i + j == k) return true;
            if (i + j < k)  i = l.next();
            else j = r.next();
        }
        return false;
    }
};