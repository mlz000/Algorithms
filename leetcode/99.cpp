class Solution {
public:
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(first -> val, second -> val);
    }
    void dfs(TreeNode* root){
        if (!root)  return;
        dfs(root -> left);
        if(!first && prev -> val >= root -> val)   first = prev;
        if(first && prev -> val >= root -> val)   second = root;
        prev = root;
        dfs(root -> right);
    }
};