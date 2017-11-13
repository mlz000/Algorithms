/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void dfs(TreeNode* rt, ostringstream& out) {
        if (rt) {
            out << to_string(rt -> val) << " ";
            dfs(rt -> left, out);
            dfs(rt -> right, out);
        }
        else {
            out << "# ";
            return;
        }
    }
    string serialize(TreeNode* root) {
        ostringstream out;
        dfs(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* dfs2(istringstream& in) {
        string t;
        in >> t;
        if (t == "#")   return NULL;
        TreeNode* rt = new TreeNode(stoi(t));
        rt -> left = dfs2(in);
        rt -> right = dfs2(in);
        return rt;
    }
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return dfs2(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));