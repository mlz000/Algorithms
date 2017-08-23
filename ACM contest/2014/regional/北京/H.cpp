#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 50, M = (1 << 20);
int a[N];
long long dp[2][M];
int main() {
	int n, m, T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt) {
		memset(dp[0], 0, sizeof(dp[0]));
		printf("Case #%d: ", tt);
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
		dp[0][0] = 1ll;
		for (int i = 1; i <= n; ++i) {
			memset(dp[i & 1], 0, sizeof(dp[i & 1]));
			for (int j = M - 1; j >= 0; --j)	dp[i & 1][j] = dp[(i - 1) & 1][j];
			for (int j = M - 1; j >= 0; --j) {
				if (dp[(i - 1) & 1][j]) {
					dp[i & 1][j ^ a[i]] += dp[(i - 1) & 1][j];
				}
			}
		}
		long long ans = 0ll;
		for (int i = m; i < M ; ++i)	ans += dp[n & 1][i];
		printf("%I64d\n", ans);
	}
	return 0;
}
