const int N = 50005, inf = 0x3f3f3f3f;
int dp[N][2];//not buy buy
class Solution {
public:
    int maxProfit(vector<int>& a, int fee) {
        int n = a.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 2; ++j)
                dp[i][j] = -inf;
        if (n == 1) return 0;
        dp[0][0] = 0;
        dp[0][1] = -a[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
            dp[i][0] = max(dp[i][0], dp[i - 1][1] + a[i] - fee);
            dp[i][1] = max(dp[i][1], dp[i][0] - a[i]);
        }
        return dp[n - 1][0];
    }
};