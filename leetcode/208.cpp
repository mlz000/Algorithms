struct trie {
	vector<trie*> son;
	bool ok;
	trie() : son(vector<trie*>(26, NULL)), ok(0){}
};
class Trie {
public:
	vector<trie*> son;
	bool ok;
	trie *rt;
    Trie() {
        rt = new trie();
    }
	void insert(string s) {
		trie* now = rt;
		for (auto c : s) {
			if (!now -> son[c - 'a'])	now -> son[c - 'a'] = new trie();
			now = now -> son[c - 'a'];
		}
		now -> ok = 1;
	}
    bool search(string s) {
        trie* now = rt;
        for (auto c : s) {
            if (now -> son[c - 'a'])    
                now = now -> son[c - 'a'];
            else return 0;
        }
        return now -> ok;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string s) {
        trie* now = rt;
        for (auto c : s) {
            if (now -> son[c - 'a']) {
                now = now -> son[c - 'a'];
                continue;
            }
            return 0;
        }
        return 1;
    }
};