#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N = 55, inf = 100000000;
int n, m, k, p[N], w[N], fw[N], d[N][N], pos[N][N], get[N][N], dp[1 << 8][1 << 8][N];
void init() {
	for (int i = 0; i <= 50; ++i) {
		for (int j = 0; j <= 50; ++j) {
			d[i][j] = inf;
			pos[i][j] = 0;
			get[i][j] = 0;
		}
		d[i][i] = 0;
	}
	for (int i = 0; i < (1 << 8); ++i)
		for (int j = 0; j < (1 << 8); ++j)
			for (int l = 0; l <= 50; ++l)
				dp[i][j][l] = inf;
}
void floyd() {
	for (int c = 1; c <= n; ++c)
		for (int a = 1; a <= n; ++a)
			for (int b = 1; b <= n; ++b)
				if (d[a][c] + d[c][b] < d[a][b])	d[a][b] = d[a][c] + d[c][b];
}
int solve() {
	d[0][1] = 0;
	dp[0][0][0] = 0;
	for (int i = 0; i < (1 << k); ++i) 
		for (int j = 0; j < (1 << k); ++j)
			if((i & j) == j) {
				for (int u = 0; u <= n; ++u)
					if(dp[i][j][u] < inf) {
						for (int v = 1; v <= n; ++v)
							if (u != v && pos[u][v] < inf) {
								int mask1 = i, mask2 = j, cost = 0;
								for (int l = 1; l <= k; ++l)	
									if (get[v][l])	mask1 |= (1 << (l - 1));
								for (int l = 1; l <= k; ++l)	
									if (pos[v][l])	mask2 |= (1 << (l - 1));
								if (dp[i][j][u] + d[u][v] < dp[mask1][j][v]) {
									dp[mask1][j][v] = dp[i][j][u] + d[u][v];
								}
								for (int l = 1; l <= k; ++l) {
									if (((j >> (l - 1) & 1) == 0) && ((mask2 >> (l - 1)) & 1))	cost += ((mask1 >> (l - 1)) & 1) ? fw[l] : w[l];
								}
								mask1 |= mask2;
								if (dp[i][j][u] + d[u][v] + cost < dp[mask1][mask2][v]) {
									dp[mask1][mask2][v] = dp[i][j][u] + d[u][v] + cost;
								}
							}
				} 
			}
	return dp[(1 << k) - 1][(1 << k) - 1][1];
}
int main() {
	int T, num;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt) {
		printf("Case #%d: ", tt);
		scanf("%d%d%d", &n, &m, &k);
		init();
		for (int i = 1, x, y, z; i <= m; ++i) {
			scanf("%d%d%d", &x, &y, &z);
			d[x][y] = d[y][x] = min(d[x][y], z);	
		}
		floyd();
		for (int i = 1, x, y; i <= k; ++i) {
			scanf("%d%d%d%d", &x, &w[i], &fw[i], &num);
			pos[x][i] = 1;
			for (int j = 1; j <= num; ++j) {
				scanf("%d", &y);
				get[y][i] = 1;
			}
		}
		int ans;
		ans = solve();
		printf("%d\n", ans);	
	}
	return 0;
}
