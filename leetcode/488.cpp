#define F first 
#define S second
typedef pair<int, int> pii;
class Solution {
public:
    map<char, int> G;
    int cnt[5], st[5], st2[5];
    int findMinStep(string s, string t) {
        int n = s.size(), m = t.size(); 
        G['R'] = 0, G['Y'] = 1, G['B'] = 2, G['G'] = 3, G['W'] = 4;
        for (auto c : t)    ++cnt[G[c]];
        bool dp[n + 1][n + 1][6][6][6][6][6];
        memset(dp, 0, sizeof(dp));
        pii a[n + 1];
        int j = 0;
        a[j].F = 10000;
        for (auto c : s) {
            if (G[c] != a[j].F) a[++j].F = G[c];
            ++a[j].S;
        }
        n = j;
        for (int i = 1; i <= n; ++i) {
            int need = (a[i].S == 1) ? 2 : 1;
            if (a[i].F == 0)    dp[i][i][need][0][0][0][0] = 1;
            else if (a[i].F == 1)   dp[i][i][0][need][0][0][0] = 1;
            else if (a[i].F == 2)   dp[i][i][0][0][need][0][0] = 1;
            else if (a[i].F == 3)   dp[i][i][0][0][0][need][0] = 1;
            else dp[i][i][0][0][0][0][need] = 1;
        }
        for (int l = 2; l <= n; ++l)
            for (int i = 1; i + l - 1 <= n; ++i) {
                j = i + l - 1;
                for (st[0] = 0; st[0] <= cnt[0]; ++st[0])
                    for (st[1] = 0; st[1] <= cnt[1]; ++st[1])
                        for (st[2] = 0; st[2] <= cnt[2]; ++st[2]) 
                            for (st[3] = 0; st[3] <= cnt[3]; ++st[3])
                                for (st[4] = 0; st[4] <= cnt[4]; ++st[4]){
                                    if (a[i].F == a[j].F) {
                                        int need = (a[i].S + a[j].S <= 2) ? 1 : 0;
                                        int now = st[a[i].F] + need;
                                        if (now <= cnt[a[i].F]) {
                                            int t = dp[i + 1][j - 1][st[0]][st[1]][st[2]][st[3]][st[4]];
                                            if (a[i].F == 0)    dp[i][j][now][st[1]][st[2]][st[3]][st[4]] |= t;
                                            else if (a[i].F == 1)   dp[i][j][st[0]][now][st[2]][st[3]][st[4]] |= t;
                                            else if (a[i].F == 2)   dp[i][j][st[0]][st[1]][now][st[3]][st[4]] |= t;
                                            else if (a[i].F == 3)   dp[i][j][st[0]][st[1]][st[2]][now][st[4]] |= t;
                                            else dp[i][j][st[0]][st[1]][st[2]][st[3]][now] |= t;
                                        }
                                    }
                                    for (int k = i; k < j; ++k)
                                        for (st2[0] = 0; st2[0] <= st[0]; ++st2[0])
                                            for (st2[1] = 0; st2[1] <= st[1]; ++st2[1])
                                                for (st2[2] = 0; st2[2] <= st[2]; ++st2[2])
                                                    for (st2[3] = 0; st2[3] <= st[3]; ++st2[3])
                                                        for (st2[4] = 0; st2[4] <= st[4]; ++st2[4]) {
                                                            dp[i][j][st[0]][st[1]][st[2]][st[3]][st[4]] |= dp[i][k][st2[0]][st2[1]][st2[2]][st2[3]][st2[4]] && dp[k + 1][j][st[0] - st2[0]][st[1] - st2[1]][st[2] - st2[2]][st[3] - st2[3]][st[4] - st2[4]];
                                                            if (k >= i + 2 && j >= k + 2 && a[i].F == a[j].F && a[k].F == a[i].F && a[i].S + a[j].S + a[k].S <= 4) {
                                                                dp[i][j][st[0]][st[1]][st[2]][st[3]][st[4]] |= dp[i + 1][k - 1][st2[0]][st2[1]][st2[2]][st2[3]][st2[4]] && dp[k + 1][j - 1][st[0] - st2[0]][st[1] - st2[1]][st[2] - st2[2]][st[3] - st2[3]][st[4] - st2[4]];
                                                            }
                                                        }

                                }
            }
        int ans = 1000000;
        for (int a = 0; a <= cnt[0]; ++a)
            for (int b = 0; b <= cnt[1]; ++b)
                for (int c = 0; c <= cnt[2]; ++c)
                    for (int d = 0; d <= cnt[3]; ++d)
                        for (int e = 0; e <= cnt[4]; ++e)   
                            if (dp[1][n][a][b][c][d][e])    ans = min(ans, a + b + c + d + e);
        return ans == 1000000 ? -1 : ans;
    }
};
