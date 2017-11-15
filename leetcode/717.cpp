bool dp[1001];
class Solution {
public:
    bool isOneBitCharacter(vector<int>& a) {
        int n = a.size();
        if (n == 1) return true;
        memset(dp, 0, sizeof(dp));
        if (a[0] == 0)    dp[0] = 1;
        if (a[0] == 1)    dp[1] = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] == 0)    dp[i] |= dp[i - 1];
            if (a[i - 1] == 1 && i >= 2)  dp[i] |= dp[i - 2];
        }
        return dp[n - 2];
    }
};