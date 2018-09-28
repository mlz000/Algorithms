class AutocompleteSystem {
public:
    /*
    struct Trie {
        bool isWord;
        unordered_map<char, Trie*> son;
        Trie() : isWord(0) {}
    };
    void del(Trie* rt) {
        for (auto& x : rt -> son) {
            if (x.second != nullptr) del(s.second);
        }
        delete rt;
    }
    Trie* root;
    void insert(string s, int cnt) {
        Trie* now = root;
        for (auto c : s) {
            if (now -> son[c])  now = now -> son[c];
            else now -> son[c] = Trie();
        }
    }
    */
    struct pis {
        string s;
        int tot;
        pis(int _tot, string _s) : s(_s), tot(_tot) {}
        bool operator < (const pis& b) const{
            if (tot < b.tot)    return 1;
            else if (tot > b.tot)   return 0;
            if (tot == b.tot)   return s > b.s;
        }
    };
    unordered_map<string, unordered_map<string, int> > cnt; 
    string now;
    vector<string> ans;
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        for (int i = 0; i < sentences.size(); ++i) {
            string s = sentences[i];
            for (int j = 1; j <= s.size(); ++j)
                cnt[s.substr(0, j)].insert(make_pair(s, times[i]));
        }
    }
    ~AutocompleteSystem() {
        cnt.clear();
        now = "";
    }
    vector<string> input(char c) {
        if (c == '#') {
            for (int j = 1; j <= now.size(); ++j)
                cnt[now.substr(0, j)][now] += 1;
            now = "";
            return {};
        }
        now += c;
        ans.clear();
        priority_queue<pis> tmp;
        auto list = cnt[now];
        for (auto it : list) {
            tmp.push(pis(it.second, it.first));
        }
        for (int i = 0; i < min(3, (int)cnt[now].size()); ++i) {     
            string res = tmp.top().s;
            tmp.pop();
            ans.push_back(res);
        }
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */