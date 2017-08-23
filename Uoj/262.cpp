#include <bits/stdc++.h>
using namespace std;
const double inf = 1e20;
const int N = 2005, V = 305;
double p[N], dp[N][N][2];
int c[N], d[N], dis[V][V];
int main() {
	int n, m, v, e;
	scanf("%d%d%d%d", &n, &m, &v, &e);
	for (int i = 1; i <= n; ++i)	scanf("%d", &c[i]);
	for (int i = 1; i <= n; ++i)	scanf("%d", &d[i]);
	for (int i = 1; i <= n; ++i)	scanf("%lf", &p[i]);
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			dp[i][j][0] = dp[i][j][1] = inf;
	for (int i = 1; i <= v; ++i) {
		for (int j = 1; j <= v; ++j)
			dis[i][j] = 100000000;
		dis[i][i] = 0;
	}
	dp[1][0][0] = dp[1][1][1] = 0.0;
	for (int i = 1, x, y, z; i <= e; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		dis[y][x] = dis[x][y] = min(dis[x][y], z);
	}
	for (int k = 1; k <= v; ++k)
		for (int i = 1; i <= v; ++i)
			for (int j = 1; j <= v; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 2; i <= n; ++i)
		for (int j = 0; j <= min(i, m); ++j) {
			dp[i][j][0] = min(dp[i - 1][j][0] + dis[c[i - 1]][c[i]], dp[i - 1][j][1] + p[i - 1] * dis[d[i - 1]][c[i]] + (1 - p[i - 1]) * dis[c[i - 1]][c[i]]);
			if (j)	dp[i][j][1] = min(dp[i - 1][j - 1][0] + p[i] * dis[c[i - 1]][d[i]] + (1 - p[i]) * dis[c[i - 1]][c[i]], dp[i - 1][j - 1][1] + p[i - 1] * p[i] * dis[d[i - 1]][d[i]] + p[i - 1] * (1 - p[i]) * dis[d[i - 1]][c[i]] + (1 - p[i - 1]) * p[i] * dis[c[i - 1]][d[i]] + (1 - p[i - 1]) * (1 - p[i]) * dis[c[i - 1]][c[i]]);
		}
	double ans = inf;
	for (int j = 0; j <= m; ++j)
		for (int k = 0; k <= 1; ++k)
			ans = min(ans, dp[n][j][k]);
	printf("%.2lf\n", ans);
	return 0;
}
