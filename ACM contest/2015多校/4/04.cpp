#include <bits/stdc++.h>//dp
using namespace std;
#define pb push_back
typedef long long LL;
const int N = 300005;
int a[N], p[15];
LL ans[25], dp[2][177147][25];
int main() {
	int T;
	p[0] = 1;
	for (int i = 1; i < N; ++i)	p[i] = p[i - 1] * 3;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < p[m]; ++i)
			for (int j = 0; j <= m * 2; ++j)
				dp[0][i][j] = dp[1][i][j] = 0;
		for (int i = 0; i < n; ++i) {
			int t = 0;
			char s[N];
			scanf("%s", s);
			for (int j = 0; j < m; ++j)	t = t * 3 + s[j] - '0';
			a[i] = t;
			++dp[0][a[i]][0];
		}
		int cur = 0;
		for (int i = 0; i < m; ++i) {
			cur ^= 1;
			for (int j = 0; j < p[m]; ++j)
				for (int k = 0; k <= 2 * m; ++k)
					dp[cur][j][k] = dp[cur ^ 1][j][k];
			for (int mask = 0; mask < p[m]; ++mask) {
				int s = mask / p[i] % 3;
				for (int j = 0; j < 3; ++j) {
					if (j == s)	continue;
					for (int k = 0; k <= 2 * m; ++k)	dp[cur][mask - (s - j) * p[i]][k + abs(s - j)] += dp[cur ^ 1][mask][k];
				}
			}
		}
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j <= 2 * m; ++j)
				ans[j] += dp[cur][a[i]][j];
		ans[0] -= n;
		for (int i = 0; i <= m * 2; ++i)	printf("%I64d\n", ans[i] / 2);
	}
	return 0;
}
