struct trie {
	vector<trie*> son;
	trie() : son(vector<trie*>(2, NULL)) {}
};

class Solution {
public:
    trie *rt;
    void insert(int x) {
		trie* now = rt;
		for (int i = 31; i >= 0; --i) {
			if (!now -> son[x >> i & 1])	now -> son[x >> i & 1] = new trie();
			now = now -> son[x >> i & 1];
		}
	}
    int find(int x) {
        trie * now = rt;
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            if (now -> son[!(x >> i & 1)])  ans |= 1 << i, now = now -> son[!(x >> i & 1)];
            else now = now -> son[x >> i & 1];
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& a) {
        int ans = 0;
        rt = new trie();
        for (auto &x : a)   insert(x);
        for (auto &x : a) {
            ans = max(ans, find(x));
        }
        return ans;
    }
};