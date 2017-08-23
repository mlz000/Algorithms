#include <bits/stdc++.h>
using namespace std;
const int N = 10005, M = 1005, inf = 0x3f3f3f3f;
int x[N], y[N], l[N], h[N], f[N][M];
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)	scanf("%d%d", &x[i], &y[i]), l[i] = 0, h[i] = m + 1;
	for (int i = 0, x; i < k; ++i) {
		scanf("%d", &x);
		scanf("%d%d", &l[x], &h[x]);
	}
	memset(f, 0x3f3f3f3f, sizeof(f));
	for (int i = 1; i <= m; ++i)	f[0][i] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (j >= x[i])	f[i][j] = min(f[i][j], min(f[i - 1][j - x[i]], f[i][j - x[i]]) + 1);
			if (j == m) {
				for (int k = j - x[i]; k <= m; ++k)
					f[i][j] = min(f[i][j], min(f[i - 1][k], f[i][k]) + 1);
			}
		}
		for (int j = l[i] + 1; j <= h[i] - 1; ++j)
			if (j + y[i] <= m)	f[i][j] = min(f[i][j], f[i - 1][j + y[i]]);
		for (int j = 1; j <= m; ++j)
			if (j <= l[i] || j >= h[i])	f[i][j] = inf;
	}
	int cnt = k, ans = inf;
	for (int i = 1; i <= m; ++i)	ans = min(ans, f[n][i]);
	for (int i = n; i >= 1; --i) {
		for (int j = l[i] + 1; j <= h[i] - 1; ++j)
			ans = min(ans, f[i][j]);
		if (ans != inf)	break;
		if (h[i] <= m)	--cnt;
	}
	if (cnt != k)	printf("0\n%d\n", cnt);
	else printf("1\n%d\n", ans);
	return 0;
}
