int path[20005][4];
struct data {
    long long mx;
    int a[4];
}dp[20005][4];
vector<int> res;
long long sum[20005];
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& b, int k) {
        int n = b.size();
        memset(dp, 0, sizeof(dp));
        memset(path, 0x3f3f3f3f, sizeof(path));
        for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + (long long)b[i];
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i - 1][0];
            for (int j = 1; j <= 3; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (i >= k) {
                    if (dp[i - k][j - 1].mx + sum[i] - sum[i - k] > dp[i][j].mx) {
                        dp[i][j] = dp[i - k][j - 1];
                        dp[i][j].mx = dp[i - k][j - 1].mx + sum[i] - sum[i - k];
                        dp[i][j].a[j] = i - k + 1;
                    }
                }
            }
        }
        res.clear();
        data now = dp[n][3];
        for (int i = 3; i >= 1; --i) {
            res.push_back(now.a[i] - 1);
            now = dp[now.a[i] - 1][i - 1];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};