#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 505, M = 1e6 + 5, mod = (int)1e9 + 7;
int dp[N][N * N / 2], sum[N][N * N / 2], c[N][N], p[N];
void init() {// i length permutation with j inversions
	for (int i = 1; i <= 500; ++i) {
		dp[i][0] = sum[i][0] = 1;
		int e = i * (i - 1) / 2;
		for (int j = 1; j <= e; ++j) {
			int t = (dp[i][j - 1] + dp[i - 1][j]) % mod;
			if (j >= i)	t = (t - dp[i - 1][j - i] + mod) % mod;
			dp[i][j] = t;
			sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
		}
	}
	p[0] = 1;
	for (int i = 0; i <= 500; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
		if (i >= 1)	p[i] = (LL)p[i - 1] * i % mod;
	}
}
int main() {
	int T;
	init();
	scanf("%d", &T);
	while (T--) {
		int n, e;
		scanf("%d%d", &n, &e);
		LL ans = 0;
		if (e > n * (n - 1) / 2)	e = n * (n - 1) / 2;
		for (int i = 1; i <= n; ++i) {
			LL t = 1ll;
			int te = min(e, i * (i - 1) / 2);
			t = t * c[n][i] % mod * c[n][i] % mod;
			t = t * p[n - i] % mod * p[n - i] % mod;
			t = t * sum[i][te] % mod * (n - i + 1) % mod;
			ans = (ans + t) % mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
