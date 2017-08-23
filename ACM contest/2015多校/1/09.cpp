#include <bits/stdc++.h>//dfs–Ú
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000") 
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 1e5 + 5;
int tot, idx, to[N << 1], nxt[N << 1], head[N], dep[N], q[N], w[N << 1], dis[N], top[N], sz[N], pre[N], son[N], id[N], dfn[N];
bool vis[N];
void add(int u, int v, int d) {
	to[tot] = v, nxt[tot] = head[u], w[tot] = d, head[u] = tot++;
	to[tot] = u, nxt[tot] = head[v], w[tot] = d, head[v] = tot++;
}
set<int> S;
void init() {
	S.clear();
	tot = idx = 0;
	memset(head, -1, sizeof(head));
	memset(vis, 0, sizeof(vis));
	memset(son, 0, sizeof(son));
	memset(pre, 0, sizeof(pre));
	memset(sz, 0, sizeof(sz));
	memset(top, 0, sizeof(top));
}
void gao() {
	int r = 0;
	vis[dep[1] = q[0] = 1] = 1;
	for (int i = 0; i <= r; ++i)
		for (int j = head[q[i]]; ~j; j = nxt[j]) 
			if (!vis[to[j]]){
				vis[to[j]] = 1;
				dep[q[++r] = to[j]] = dep[q[i]] + 1;
				pre[q[r]] = q[i];
			}
	for (int i = r; i >= 0; --i) {
		sz[pre[q[i]]] += ++sz[q[i]];
		if (sz[son[pre[q[i]]]] < sz[q[i]])	son[pre[q[i]]] = q[i];
	}
	for (int i = 0; i <= r; ++i)
		if (!top[q[i]]) {
			for (int j = q[i]; j; j = son[j])	top[j] = q[i];
		}
}
void dfs(int u, int fa, int now) {
	dis[u] = now;
	dfn[u] = ++idx;
	id[idx] = u;
	for (int i = head[u]; ~i; i = nxt[i]) {
		int v = to[i];
		if (v == fa)	continue;
		dfs(v, u, now + w[i]);
	}
}
int lca(int a, int b) {
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]])	swap(a, b);
		a = pre[top[a]];
	}
	if (dep[a] > dep[b])	swap(a, b);
	return a;
}
int work(int x) {
	if (!S.size())	return 0;
	set<int>:: iterator it = S.upper_bound(dfn[x]);
	int a, b;
	if (it == S.begin() || it == S.end()) {
		a = id[*S.begin()];
		b = id[*S.rbegin()];
	}
	else {
		a = id[*it];
		it--;
		b = id[*it];
	}
	return dis[x] - dis[lca(x, a)] - dis[lca(x, b)] + dis[lca(a, b)];
}
int main() {
	int T;
	read(T);
	for (int tt = 1; tt <= T; ++tt) {
		printf("Case #%d:\n", tt);
		int n, q;
		init();
		read(n), read(q);
		for (int i = 1, x, y, z; i < n; ++i) {
			read(x), read(y), read(z);
			add(x, y, z);
		}
		gao();
		dfs(1, 0, 0);
		memset(vis, 0, sizeof(vis));
		int ans = 0;
		for (int i = 1; i <= q; ++i) {
			int op, x;
			read(op), read(x);
			if (op == 1 && !vis[dfn[x]]) {
				ans += work(x);
				S.insert(dfn[x]);
				vis[dfn[x]] = 1;
			}
			if (op == 2 && vis[dfn[x]]) {
				S.erase(dfn[x]);
				vis[dfn[x]] = 0;
				ans -= work(x);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
