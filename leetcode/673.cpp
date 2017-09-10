//Given an unsorted array of integers, find the number of longest increasing subsequence. N <= 2000
class Solution {
public:
    int dp[2001][2];
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size(), mx = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            dp[i][0] = dp[i][1] = 1;
            for (int j = 0; j < i; ++j) {
                if (a[j] < a[i]) {
                    if (dp[j][0] + 1 > dp[i][0])    dp[i][0] = dp[j][0] + 1, dp[i][1] = dp[j][1];
                    else if (dp[j][0] + 1 == dp[i][0])  dp[i][0] = dp[j][0] + 1, dp[i][1] += dp[j][1];
                }
            }
            mx = max(mx, dp[i][0]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (dp[i][0] == mx) ans += dp[i][1];
        return ans;
    }
};