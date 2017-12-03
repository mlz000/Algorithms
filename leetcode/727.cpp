class Solution {
public:
    string minWindow(string S, string T) {
        vector<vector<int> > dp(S.size() + 1, vector<int>(T.size() + 1, 1000000));
        for (int i = 0; i < S.size(); ++i)
            if (S[i] == T[0])   dp[i][0] = 1;
        for (int i = 1; i < S.size(); ++i)
            for (int j = 0; j < T.size(); ++j) {
                if (S[i] == T[j]) {
                    if (j > 0) dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                }
            }
        int p, ans = 1e6;
        for (int i = 0; i < S.size(); ++i)
            if (dp[i][T.size() - 1] < ans) {
                ans = dp[i][T.size() - 1];
                p = i;
            }
        if (ans == 1e6) return "";
        return S.substr(p - ans + 1, ans);
    }
};