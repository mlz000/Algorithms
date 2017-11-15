struct Trie {
	vector<Trie*> son;
	bool ok;
	Trie() : son(vector<Trie*>(26, NULL)), ok(0){}
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    Trie* rt;
    WordDictionary() {
        rt = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Trie* now = rt;
        for (auto c : word) {
            if (!now -> son[c - 'a'])  now -> son[c - 'a'] = new Trie();
            now = now -> son[c - 'a'];
        }
        now -> ok = 1;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool dfs(Trie* now, string s) {
        if (s.size() == 0)  return now -> ok;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '.') {
                if (now -> son[s[i] - 'a']) return dfs(now -> son[s[i] - 'a'], s.substr(1));
                else return 0;
            }
            else {
                bool ok = 0;
                for (int j = 0; j < 26; ++j) {
                    if (now -> son[j] && dfs(now -> son[j], s.substr(1))) {
                        ok = 1;
                        break;
                    }
                }
                return ok;
            }
        }
    }
    bool search(string word) {
        Trie* now = rt;
        return dfs(now, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */