#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 55, M = (int)1e9 + 7;
long long dp[2][8];
int p[N][N];
long long po[N];
int main() {
    int n, m, T;
    scanf("%d", &T);
    long long inv;
    po[0] = 1ll;
    for (int i = 1; i <= 50; ++i)    po[i] = po[i - 1] * 2 % M;
    inv= (M - M / 2);
    for (int tt = 1; tt <= T; ++tt) {
        memset(p, 0, sizeof(p));
        printf("Case #%d: ", tt);
        scanf("%d%d", &n, &m);
        for (int i = 1, x, y; i <= m; ++i) {
            scanf("%d", &x);
            while (x--) {
                scanf("%d", &y);
                p[i][y] = 1;
            }
        }
        long long ans = 0ll;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= i; ++j)
                for (int k = 1; k <= j; ++k) {
                    memset(dp, 0, sizeof(dp));
                    dp[0][0] = po[m];
                    for (int l = 1; l <= m; ++l) {
                        for (int mask = 0; mask < 8; ++mask)
                            if (dp[(l - 1) & 1][mask]) {
                                int t = 0;
                                if (p[l][i])    t |= 4;
                                if (p[l][j])    t |= 2;
                                if (p[l][k])    t |= 1;
                                (dp[l & 1][mask ^ t] += dp[(l - 1) & 1][mask] * inv % M) %= M;
                                (dp[l & 1][mask] += dp[(l - 1) & 1][mask] * inv % M) %= M;
                            }
                        }
					if (i != j && i != k && j != k)	(ans += dp[m & 1][7] * 6 % M) %= M;
                	else if (i == j && i == k && j == k) (ans += dp[m & 1][7]) %= M;
					else (ans += dp[m & 1][7] * 3 % M) %= M;
				}
        printf("%I64d\n", ans % M);
    }
    return 0;
}
