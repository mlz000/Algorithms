const int M = 1e9 + 7;
class Solution {
public:
    int pre[1005][5], nxt[1005][5];
    vector<vector<int> > dp;
    string s;
    int dfs(int l, int r) {
        if (l > r)  return 0;
        if (l == r) return 1;
        if (~dp[l][r])  return dp[l][r];
        int &t = dp[l][r];
        t = 0;
        if (s[l] != s[r])   return (t = ((dfs(l + 1, r) + dfs(l, r - 1)) % M + M - dfs(l + 1, r - 1)) % M);
        else {
            int p1 = nxt[l + 1][s[l] - 'a'], p2 = pre[r - 1][s[l] - 'a'];
            (t += dfs(l + 1, r - 1) * 2 % M) %= M;
            if (p1 < 0  || p1 >= r)  t += 2;
            else if (p1 == p2)  t += 1;
            else (t += M - dfs(p1 + 1, p2 - 1)) %= M;
        }
        return t;
    }
    int countPalindromicSubsequences(string S) {
        int n = S.size();
        s = S;
        memset(pre, -1, sizeof(pre));
        memset(nxt, -1, sizeof(nxt));
        dp.assign(n + 2, vector<int> (n + 2, -1));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 4; ++j) {
                if (S[i] == 'a' + j)    pre[i][j] = i;
                else if (i > 0) pre[i][j] = pre[i - 1][j];
            }
        for (int i = n - 1; i >= 0; --i)
            for (int j = 0; j < 4; ++j) {
                if (S[i] == 'a' + j)    nxt[i][j] = i;
                else nxt[i][j] = nxt[i + 1][j];
            }
        cout << S.size() << endl;;
        return dfs(0, n - 1);
    }
};