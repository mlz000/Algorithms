#include <bits/stdc++.h>
using namespace std;
const int N = 15, inf = 1 << 30;
int n, m, k, a[N][N], p[N][N], dp[N][N][1 << 10];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool vis[N][N][1 << 10], vs[N][N];
struct data {
	int x, y, mask;
	data(){}
	data(int x, int y, int mask): x(x), y(y), mask(mask)	{} 
}father[N][N][1 << 10];
queue<data> q;
void spfa() {
	while (q.size()) {
		data t = q.front();
		q.pop();
		vis[t.x][t.y][t.mask] = 0;
		for (int i = 0; i < 4; ++i) {
			int tx = t.x + dx[i], ty = t.y + dy[i], tmask = t.mask | p[tx][ty];
			if (dp[tx][ty][tmask] > dp[t.x][t.y][t.mask] + a[tx][ty]) {
				dp[tx][ty][tmask] = dp[t.x][t.y][t.mask] + a[tx][ty];
				father[tx][ty][tmask] = t;
				if (!vis[tx][ty][tmask])	vis[tx][ty][tmask] = 1, q.push(data(tx, ty, tmask));
			}
		}
	}
}
void print(int x, int y, int mask) {
	vs[x][y] = 1;
	if (mask == p[x][y])	return ;
	data t = father[x][y][mask];
	print(t.x, t.y, t.mask);
	if (t.x == x && t.y == y)	print(t.x, t.y, (mask ^ t.mask) | p[t.x][t.y]);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
			if (!a[i][j])	p[i][j] = 1 << k, k++;
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			for (int l = 0; l < (1 << k); ++l)	dp[i][j][l] = inf;
			if (!a[i][j])	dp[i][j][p[i][j]] = 0;
		}
	for (int mask = 1; mask < (1 << k); ++mask) {
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				if (!a[i][j] && (!(mask & p[i][j])))	continue;
				for (int s = (mask - 1) & mask; s; s = (s - 1) & mask) {
					int t = dp[i][j][s | p[i][j]] + dp[i][j][(mask ^ s) | p[i][j]] - a[i][j];
					if (dp[i][j][mask] > t)	dp[i][j][mask] = t, father[i][j][mask] = data(i, j, s | p[i][j]);
				}
				if (dp[i][j][mask] != inf) q.push(data(i, j, mask)), vis[i][j][mask] = 1;
			}
		spfa();
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (!a[i][j]) {
				printf("%d\n", dp[i][j][(1 << k) - 1]);
				print(i, j, (1 << k) - 1);
				for (int c = 1; c <= n; ++c, puts("")) 
					for (int d = 1; d <= m; ++d) {
						if (!a[c][d])	printf("x");
						else if (vs[c][d])	printf("o");
						else printf("_");
					}
				return 0;
			}
	return 0;
}
