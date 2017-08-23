#include <bits/stdc++.h>
using namespace std;
const int N = 55, M = 2005, Q = N * N * 2, inf = 1e6;
int n, m, tot, ans, f[N][N * 2][M], g[M], w[N], fa[N], cost[N], can[N], to[Q], need[Q], nxt[Q], head[N];
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
void add(int u, int v, int ww) {
	to[tot] = v, need[tot] = ww, nxt[tot] = head[u], head[u] = tot++;
}
void dfs(int u) {
	if (head[u] == -1) {
		can[u] = min(can[u], m / cost[u]);
		for (int i = 0; i <= can[u]; ++i)
			for (int j = i; j <= can[u]; ++j)
				f[u][i][j * cost[u]] = (j - i) * w[u]; 
		return;
	}
	can[u] = inf;
	for (int i = head[u], v; ~i; i = nxt[i]) {
		v = to[i];
		dfs(v);
		can[u] = min(can[u], can[v] / need[i]);
	}
	for (int i = 0; i <= can[u]; ++i)	f[u][i][0] = 0;
	for (int i = head[u], v; ~i; i = nxt[i]) {
		v = to[i];
		for (int j = 0; j <= can[u]; ++j) {
			memcpy(g, f[u][j], sizeof(f[u][j]));
			memset(f[u][j], -1, sizeof(f[u][j]));
			for (int k = m; k >= 0; --k) {
				for (int l = k; l >= 0; --l) {
					if (~g[k - l] && ~f[v][j * need[i]][l])	f[u][j][k] = max(f[u][j][k], g[k - l] + f[v][j * need[i]][l]);
				}
				ans = max(ans, f[u][j][k]);
			}
		}
	}
	for (int i = 0; i <= can[u]; ++i)
		for (int j = i; j <= can[u]; ++j)
			for (int k = 0; k <= m; ++k) 
				if (~f[u][j][k]){
					f[u][i][k] = max(f[u][i][k], f[u][j][k] + (j - i) * w[u]);
					ans = max(ans, f[u][i][k]);
				}
}
int main() {
	int a, b, c;
	read(n), read(m);
	char s[5];
	memset(head, -1, sizeof(head));
	for (int i = 1; i <= n; ++i) {
		read(w[i]);
		scanf("%s", s);
		if (s[0] == 'A') {
			read(c);
			for (int j = 1; j <= c; ++j) {
				read(a), read(b);
				add(i, a, b);
				fa[a] = i;
			}
		}
		else read(cost[i]), read(can[i]);
	}
	memset(f, -1, sizeof(f));
	for (int i = 1; i <= n; ++i)
		if (!fa[i])	dfs(i);
	printf("%d\n", ans);
	return 0;
}
