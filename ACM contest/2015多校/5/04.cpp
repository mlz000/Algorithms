#include <bits/stdc++.h>//a nice dp problem!
//permutation!
using namespace std;
typedef long long LL;
const int N = 2005, M = 258280327;
LL gao(LL x, LL y) {
	LL t = 1;
	for (; y; y >>= 1) {
		if (y & 1)	t = t * x % M;
		x = x * x % M;
	}
	return t;
}
int p[N], ans[N], dp[N][N];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, x, y;
		scanf("%d%d%d", &n, &x, &y);
		int P = gao(y, M - 2) * x % M;
		p[0] = 1;
		for (int i = 1; i <= n; ++i)	p[i] = (LL)p[i - 1] * (1 - P + M) % M;
		memset(ans, 0, sizeof(ans));
		dp[0][1] = 1;//i got j attacks
		for (int i = 2; i <= n; ++i) {
			dp[0][i] = 0;
			for (int j = 1; j < i; ++j)
				dp[j][i] = ((LL)dp[j - 1][i - 1] * p[j - 1] % M + (LL)dp[j][i - 1] * (1 - p[j] + M) % M) % M;
		}
		for (int j = 0; j < n; ++j) {
			for (int i = 1; i <= n; ++i)
				(ans[j] += (LL)dp[j][i] * p[j] % M) %= M;
			ans[j] = gao(n, M - 2) * ans[j] % M;
		}
		for (int j = 0; j < n - 1; ++j)	printf("%d ", ans[j]);
		printf("%d\n", ans[n - 1]);
	}
	return 0;
}
