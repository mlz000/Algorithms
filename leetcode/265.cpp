class Solution {
public:
    int minCostII(vector<vector<int>>& cost) {
        int n = cost.size();
        if (n == 0) return 0;
        int k = cost[0].size();
        vector<vector<long long> > dp(n, vector<long long>(k + 2, INT_MAX));
        vector<long long> mnl(k + 2, INT_MAX), mnr(k + 2, INT_MAX);
        for (int i = 1; i <= k; ++i) {
            dp[0][i] = cost[0][i - 1];
            mnl[i] = min(mnl[i - 1], dp[0][i - 1]);
        }
        for (int i = k; i >= 1; --i) {
            mnr[i] = min(mnr[i + 1], dp[0][i + 1]);
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = min(dp[i][j], min(mnl[j], mnr[j]) + cost[i][j - 1]);
            }
            for (int j = 1; j <= k; ++j)    mnl[j] = mnr[j] = INT_MAX;
            for (int j = 1; j <= k; ++j)
                mnl[j] = min(mnl[j - 1], dp[i][j - 1]);
            for (int j = k; j >= 1; --j)
                mnr[j] = min(mnr[j + 1], dp[i][j + 1]);
        }
        long long ans = INT_MAX;
        for (int j = 1; j <= k; ++j)    ans = min(ans, dp[n - 1][j]);
        return ans;
    }
};