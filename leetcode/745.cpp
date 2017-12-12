#define mp make_pair
class WordFilter {
public:
    unordered_map<string, int> G;
    WordFilter(vector<string> words) {
        int k = 0;
        G.clear();
        for (auto s : words) {  
            for (int i = 0; i <= s.size(); ++i) {
                string a = s.substr(0, i);
                for (int j = 0; j <= s.size(); ++j) {
                    string b = s.substr(j);
                    reverse(b.begin(), b.end());
                    G[a + "$" + b] = k;
                }
            }
            ++k;
        }
    }
    
    int f(string prefix, string suffix) {
        string s = prefix + "$" + string(suffix.rbegin(), suffix.rend());
        if (!G.count(s))   return -1;
        return G[s];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */