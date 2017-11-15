/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode *root) {
        while (s.size())    s.pop();
        left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (s.size())  return 1;
        return 0;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* t = s.top();
        s.pop();
        if (t -> right) left(t -> right);
        return t -> val;
    }
    void left(TreeNode* rt) {
        TreeNode* t = rt;
        while(t) {
            s.push(t);
            t = t -> left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */