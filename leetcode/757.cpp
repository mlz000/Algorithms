class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        unordered_map<string, bool> G;
        bool v[505];
        memset(v, 0, sizeof(v));
        for (auto s : words)    G[s] = 1;
        string ans = "";
        for (int i = 0; i < S.size(); ++i) {
            for (int j = 1; i + j - 1 < S.size() && j <= 10; ++j)
                if (G[S.substr(i, j)]) {
                    for (int k = i; k < i + j; ++k) v[k] = 1;
                }
        }
        int now = 0;
        for (int i = 0; i <= S.size(); ++i) {
            if (v[i]) {
                if (!now)   ans += "<b>", now = 1;
            }
            else if (i && v[i - 1]) {
                if (now)    ans += "</b>", now = 0;
            }
            if (i < S.size())   ans += S[i];
        }
        return ans;
    }
};