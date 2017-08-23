//same as bzoj 1260....
class Solution {
public:
    int dp[100][100];
    int dfs(int l, int r, string s) {
        int &t = dp[l][r];
        if (~t) return t;
        if (l == r) return t = 1;
        if (l + 1 == r && s[l] == s[r]) return t = 1;
        t = 100;
        if (s[l] == s[r])   t = min(dfs(l + 1, r, s), dfs(l, r - 1, s));
        for (int k = l; k < r; ++k)
            t = min(t, dfs(l, k, s) + dfs(k + 1, r, s));
        return t;
    }
    int strangePrinter(string s) {
        if (s.size() == 0)  return 0;
        int l = 0, r = s.size() - 1;
        memset(dp, -1, sizeof(dp));
        return dfs(0, r, s);
    }
};