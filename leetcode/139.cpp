class Solution {
public:
    bool wordBreak(string s, vector<string>& S) {
        unordered_map<string, bool> G;
        for (auto& t : S)   G[t] = 1;
        for (int i = 0; i < s.size(); ++i)
            for (int j = 0; j < i; ++j) {
                if (G[s.substr(0, j + 1)] && G[s.substr(j + 1, i - j)])  G[s.substr(0, i + 1)] = 1;
            }
        return G[s];
    }
};