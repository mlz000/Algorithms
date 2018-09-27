const int M = 1e9 + 7;
int dp[105][105][105];
class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        int n = group.size();
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j <= G; ++j)
                for (int k = 0; k <= P; ++k) {
                    (dp[i][j][k] += dp[i - 1][j][k]) %= M;
                    int cnt = group[i - 1], v = profit[i - 1];
                    if (j + cnt <= G)   (dp[i][j + cnt][min(P, k + v)] += dp[i - 1][j][k]) %= M;
                }
        int ans = 0;
        for (int j = 0; j <= G; ++j)    (ans += dp[n][j][P]) %= M;
        return ans;
    }
};
