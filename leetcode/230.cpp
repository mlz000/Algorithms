class Solution {
public:
    int kthSmallest(TreeNode* root, int& k) {
        if (!root)  return -1;
        int t = kthSmallest(root -> left, k);
        if (!k) return t;
        if (!--k)   return root -> val;
        return kthSmallest(root -> right, k);
    }
};