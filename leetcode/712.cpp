int dp[1005][1005];
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 1; i <= n1; ++i)   dp[i][0] = dp[i - 1][0] + (int)s1[i - 1];
        for (int j = 1; j <= n2; ++j)   dp[0][j] = dp[0][j - 1] + (int)s2[j - 1];
        for (int i = 1; i <= n1; ++i)
            for (int j = 1; j <= n2; ++j) {
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                else {
                    dp[i][j] = min(dp[i][j], min(dp[i - 1][j] + (int)s1[i - 1], dp[i][j - 1] + (int)s2[j - 1]));
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (int)s1[i - 1] + (int)s2[j - 1]);
                }
                //cout << i << " " << j << " " << dp[i][j] << endl;
            }
        return dp[n1][n2];
    }
};