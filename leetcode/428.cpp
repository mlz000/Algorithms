/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:

    // Encodes a tree to a single string.
    void dfs1(Node* rt, ostringstream &out) {
        if (rt) {
            out << to_string(rt -> val) << " " << to_string(rt -> children.size()) << " ";
            for (auto node : rt -> children)
                dfs1(node, out);
        }
        else    out << "#";
    }
    string serialize(Node* root) {
        ostringstream out;
        dfs1(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    Node* dfs2(istringstream& in) {
        string t, cnt;
        in >> t >> cnt;
        if (t == "#")   return NULL;
        vector<Node*> a(stoi(cnt), NULL);
        Node* rt = new Node(stoi(t), a);
        for (int i = 0; i < stoi(cnt); ++i)
            rt -> children[i] = dfs2(in);
        return rt;
    }
    Node* deserialize(string data) {
        istringstream in(data);
        return dfs2(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));