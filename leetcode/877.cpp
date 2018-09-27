class Solution {
public:
    int dp[505][505], sum[505];
    vector<int> a;
    int dfs(int l, int r) {
        if (l > r)  return 0;
        if (~dp[l][r])  return dp[l][r];
        int &t = dp[l][r];
        t = 0;
        int t1 = a[l] + sum[r + 1] - sum[l] - dfs(l + 1, r);
        int t2 = a[r] + sum[r + 1] - sum[l] - dfs(l, r - 1);
        t = max(t1, t2);
        return t;
    }
    bool stoneGame(vector<int>& b) {
        int n = b.size(); 
        this -> a = b;
        int tot = 0;
        for (auto x: a) tot += x;
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + a[i];
        }
        memset(dp, -1, sizeof(dp));
        return dfs(0, n - 1) > tot / 2;
    }
};
