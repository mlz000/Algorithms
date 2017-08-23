#include <bits/stdc++.h>//ÐéÊ÷
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 3e5 + 5;
vector<int> g[N];
pii near[N];
int n, tot, ind, dep[N], dfn[N], sz[N], f[N][20], pos[N], h[N], t[N], st[N], fa[N], w[N], dis[N], ans[N];
bool cmp(const int &x, const int &y) {
	return dfn[x] < dfn[y];
}
int find(int x, int d) {
	for (int i = 19; i >= 0; --i)
		if (dep[f[x][i]] >= d)	x = f[x][i];
	return x;
}
int lca(int x, int y) {
	if (dep[x] < dep[y])	swap(x, y);
	for (int i = 19; i >= 0; --i)
		if (dep[f[x][i]] >= dep[y])	x = f[x][i];
	if (x == y)	return x;
	for (int i = 19; i >= 0; --i)
		if (f[x][i] != f[y][i])	x = f[x][i], y = f[y][i];
	return f[x][0];
}
void dfs(int u) {
	sz[u] = 1;
	dfn[u] = ++ind;
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i];
		if (v == f[u][0])	continue;
		f[v][0] = u;
		for (int j = 1; j <= 19; ++j)	f[v][j] = f[f[v][j - 1]][j - 1];
		dep[v] = dep[u] + 1;
		dfs(v);
		sz[u] += sz[v];
	}
}
void build(int m) {
	int top = 0;
	sort(h + 1, h + m + 1, cmp);
	for (int i = 1; i <= m; ++i) {
		if (!top)	fa[st[++top] = h[i]] = 0;
		else {
			int x = lca(st[top], h[i]);
			for (; dep[st[top]] > dep[x]; --top)
				if (dep[st[top - 1]] <= dep[x])	fa[st[top]] = x;
			if (st[top] != x) {
				fa[x] = st[top];
				t[++tot] = x;
				st[++top] = x;
				near[x] = mp(0x3f3f3f3f, 0);
			}
			fa[st[++top] = h[i]] = x;
		}
	}
}
void work() {
	tot = 0;
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &h[i]);
		t[++tot] = pos[i] = h[i], ans[h[i]] = 0, near[h[i]] = mp(0, h[i]);
	}
	build(m);
	sort(t + 1, t + tot + 1, cmp);
	for (int i = 1; i <= tot; ++i) {
		int x = t[i];
		w[x] = sz[x];
		if (i > 1)	dis[x] = dep[x] - dep[fa[x]];
	}
	for (int i = tot; i > 1; --i) {
		int x = t[i];
		near[fa[x]] = min(near[fa[x]], mp(near[x].F + dis[x], near[x].S));
	}
	for (int i = 2; i <= tot; ++i) {
		int x = t[i];
		near[x] = min(near[x], mp(near[fa[x]].F + dis[x], near[fa[x]].S));
	}
	for (int i = 1; i <= tot; ++i) {
		int x = t[i];
		if (i == 1)	ans[near[x].S] += n - sz[x];
		else {
			int rt = find(x, dep[fa[x]] + 1);
			int sum = sz[rt] - sz[x];
			w[fa[x]] -= sz[rt];
			if (near[fa[x]].S == near[x].S)	ans[near[x].S] += sum;
			else {
				int mid = dep[x] - (near[fa[x]].F - near[x].F + dis[x]) / 2;
				if ((near[fa[x]].F + near[x].F + dis[x]) % 2 == 0 && near[fa[x]].S < near[x].S)	++mid;
				int tmp = sz[find(x, mid)] - sz[x];
				ans[near[fa[x]].S] += sum - tmp;
				ans[near[x].S] += tmp;
			}
		}
	}
	for (int i = 1; i <= tot; ++i)	ans[near[t[i]].S] += w[t[i]];
	for (int i = 1; i <= m; ++i)	printf("%d ", ans[pos[i]]);
	puts("");
}
void gao() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		g[u].pb(v), g[v].pb(u);
	}
	dfs(dep[1] = 1);
	int q;
	scanf("%d", &q);
	while (q--) work();
}
int main() {
	gao();
	return 0;
}
