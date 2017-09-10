class Solution {
public:
    string Hash(TreeNode *s){
        if(!s) return "^"; 
        else return "(" + Hash(s -> left) + to_string(s -> val) + Hash(s -> right) + ")";
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return Hash(s).find(Hash(t)) != string::npos;
    }
};