class Solution {
public:
    int findLengthOfLCIS(vector<int>& a) {
        int n = a.size(), ans = 0;
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                dp[i] = 1;
                ans = 1;
                continue;
            }
            if (a[i] > a[i - 1])    dp[i] = max(dp[i], dp[i - 1] + 1);
            else dp[i] = 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};