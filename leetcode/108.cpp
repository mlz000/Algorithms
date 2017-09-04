class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.size() == 0) return NULL;
        if(num.size() == 1) {
            return new TreeNode(num[0]);
        }        
        int mid = num.size() / 2;
        TreeNode* root = new TreeNode(num[mid]);
        vector<int> l(num.begin(), num.begin() + mid);
        vector<int> r(num.begin() + mid + 1, num.end());
        root -> left = sortedArrayToBST(l);
        root -> right = sortedArrayToBST(r);
        return root;
    }
};