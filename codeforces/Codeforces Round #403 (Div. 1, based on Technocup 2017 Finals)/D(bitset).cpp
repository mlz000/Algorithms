#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 505, M = 61;
bitset<N> f[M][2][N];
LL g[M][2][N], p[M];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1, x, y, z; i <= m; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		f[0][z][x][y] = 1;
		g[0][z][x] = 1;
	}
	p[0] = 1ll;
	for (int i = 1; i < M - 1; ++i)	p[i] = p[i - 1] << 1ll;
	for (int i = 0; i < M - 1; ++i)
		for (int j = 0; j < 2; ++j)
			for (int s = 1; s <= n; ++s) {
				g[i + 1][j][s] = g[i][j][s];
				for (int t = 1; t <= n; ++t) {
					if (f[i][j][s][t]) {
						f[i + 1][j][s] |= f[i][j ^ 1][t];
						g[i + 1][j][s] = max(g[i + 1][j][s], p[i] + g[i][j ^ 1][t]);
					}
				}
			}
	LL ans = g[M - 1][0][1];
	if (ans > 1e18)	ans = -1;
	printf("%I64d\n", ans);
	return 0;
}

