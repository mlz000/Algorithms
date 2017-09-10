class MagicDictionary {
public:
    /** Initialize your data structure here. */
    unordered_map<string, bool> G;
    MagicDictionary() {
        G.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto& s : dict) {
            for (int i = 0; i < s.size(); ++i) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (s[i] != c) {
                        string t = s.substr(0, i) + c + s.substr(i + 1, s.size() - i - 1);
                        G[t] = true;
                    }
                }
            }
        }
    }
    bool search(string s) {
      return G[s];
    }
};