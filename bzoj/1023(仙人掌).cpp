#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = N << 1;
int ans, ind, tot, cnt, fa[N], cir[N << 1], to[M << 1], nxt[M << 1], head[N], dfn[N], low[N], f[N];
inline int read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
struct data {
	int p, w;
}q[N];
void add(int u, int v) {
	to[tot] = v, nxt[tot] = head[u], head[u] = tot++;
	to[tot] = u, nxt[tot] = head[v], head[v] = tot++;
}
void gao() {
	int h = 1, r = 1;
	for (int i = 1; i <= cnt; ++i)	cir[cnt + i] = cir[i];
	for (int i = 1; i <= (cnt << 1); ++i) {
		while (h < r && i - q[h].p > cnt / 2)	++h;
		while (h < r && q[r].w <= f[cir[i]] - i) --r;
		q[++r].p = i, q[r].w = f[cir[i]] - i;
		ans = max(ans, f[cir[i]] + i + q[h].w);
	}
}
void dfs(int u) {
	low[u] = dfn[u] = ++ind;
	for (int i = head[u], v; ~i; i = nxt[i]) {
		v = to[i];
		if (fa[v] != 0 && v != fa[u])	low[u] = min(low[u], dfn[v]);
		if (fa[v] == 0) {
			fa[v] = u;
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
	}
	for (int i = head[u], v; ~i; i = nxt[i]) {
		v = to[i];
		if (fa[v] == u && low[v] > dfn[u]) {	//bridge
			ans = max(ans, f[u] + f[v] + 1);
			f[u] = max(f[u], f[v] + 1);
		}
		if (fa[v] != u && dfn[u] < dfn[v]) { //circle
			cnt = 0;
			while (v != fa[u])	cir[++cnt] = v, v = fa[v];
			gao();
			for (int j = 1; j < cnt; ++j)	f[u] = max(f[u], f[cir[j]] + min(j, cnt - j));
		}
	}
}
int main() {
	int n, m;
	memset(head, -1, sizeof(head));
	read(n), read(m);
	for (int i = 1, x, y, z; i <= m; ++i) {
		read(x), read(y);
		for (int j = 1; j < x; ++j) {
			read(z);
			add(y, z);
			y = z;
		}
	}
	fa[1] = -1;
	dfs(1);
	printf("%d\n", ans);
	return 0;
}
