#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
const int N = 10005 << 1;
typedef pair<int, int> pii;
vector<int> g[N];
vector<pii> br;
int ind, n, m, q, dfn[N], low[N], f[N];
void init() {
	ind = 0;
	for (int i = 1; i <= n; ++i)	g[i].clear(), dfn[i] = low[i] = 0;
	br.clear();
}
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++ind;
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i];
		if (!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfn[u]) br.pb(mp(u, v));
		}
		else if (dfn[v] < dfn[u] && v != fa)	low[u] = min(low[u], dfn[v]);
	}
}
int main() {
	while (scanf("%d%d%d", &n, &m, &q) && n) {
		init();
		for (int i = 1, x, y; i <= m; ++i) {
			scanf("%d%d", &x, &y);
			g[x].pb(y), g[y].pb(x);
		}
		for (int i = 1; i <= n; ++i)
			if (!dfn[i])	tarjan(i, 0);
		for (int i = 1; i <= n; ++i)	f[i] = i;
		for (int i = 0; i < br.size(); ++i) {
			int fx = find(br[i].F), fy = find(br[i].S);
			if (fx != fy)	f[fx] = fy;
		}
		while (q--) {
			int x, y;
			scanf("%d%d", &x, &y);
			int fx = find(x), fy = find(y);
			printf("%s\n", fx == fy ? "Y" : "N");
		}
		puts("-");
	}
	return 0;
}
