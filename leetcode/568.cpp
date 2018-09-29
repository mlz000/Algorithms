class Solution {
public:
    int dp[105][105];
    int maxVacationDays(vector<vector<int>>& f, vector<vector<int>>& d) {
        int n = f.size(), k = d[0].size();
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
            for (int j = 0; j < k; ++j)
                dp[j][i] = -1000000;
        }
        for (int i = 0; i < k; ++i) {
            if (i == 0) {
                dp[0][0] = d[0][0];
                for (int j = 1; j < n; ++j) {
                    if (f[0][j])    dp[0][j] = d[j][0];
                }
            }
            else {
                for (int j = 0; j < n; ++j)
                    for (int k = 0; k < n; ++k) 
                        if (f[k][j]) {
                            dp[i][j] = max(dp[i][j], dp[i - 1][k] + d[j][i]);
                        }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, dp[k - 1][i]);
        return ans;
    }
};