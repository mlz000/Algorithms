#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 105, inf = (int)1e9;
int d[N][N], g[N];
int main() {
	int n, m;
	while (scanf("%d", &n) && n) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j)	d[i][j] = inf;
			d[i][i] = 0;
			g[i] = 0;
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &m);
			for (int j = 1, x, y; j <= m; ++j) {
				scanf("%d%d", &x, &y);
				d[i][x] = y;
			}
		}
		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				g[i] = max(g[i], d[i][j]);
		int Min = inf, pos;
		for (int i = 1; i <= n; ++i)
			if (Min > g[i]) {
				Min = g[i];
				pos = i;
			}
		if (Min == inf)	puts("disjoint");
		else printf("%d %d\n", pos, Min);
	}
	return 0;
}

