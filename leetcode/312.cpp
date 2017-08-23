#define pb push_back
class Solution {
public:
    vector<int> a;
    int dp[504][504];
    int gao(int l, int r) {
        if (~dp[l][r])  return dp[l][r];
        int &t = dp[l][r];
        if (l == r - 1) return t = 0;
        for (int i = l + 1; i < r; ++i)
            t = max(t, gao(l, i) + gao(i, r) + a[l] * a[i] * a[r]);
        return t;
    }
    int maxCoins(vector<int>& b) {
        a.pb(1);
        for (auto x : b)    a.pb(x);
        a.pb(1);
        int n = a.size();
        memset(dp, -1, sizeof(dp));
        return gao(0, n - 1);
    }
};