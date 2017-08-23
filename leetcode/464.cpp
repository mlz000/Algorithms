class Solution {
public:
    vector<int> dp;
    bool gao(int mask, int mx, int tot) {
        if (~dp[mask])    return dp[mask];
        for (int i = 0; i < mx; ++i)
            if (~mask >> i & 1) {
                if (i + 1 >= tot || !gao(mask | (1 << i), mx, tot - i - 1))  return dp[mask] = 1;
            }
        return dp[mask] = 0;
    }
    bool canIWin(int mx, int tot) {
        if (mx >= tot)  return 1;
        int sum = (1 + mx) * mx / 2;
        if (sum < tot)  return 0;
        dp.resize(1 << mx, -1);
        return gao(0, mx, tot);
    }
};