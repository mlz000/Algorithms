#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 3005, M = 4e5 + 5;
struct data {
	int t, k, id;
	data(int t, int k, int id) : t(t), k(k), id(id) {}
};
vector<int> g[N];
vector<data> Q[M];
int f[N], st[15][N], ans[M];
void dfs(int u, int fa) {
	for (auto& v : g[u]) {
		if (v == fa)	continue;
		if (!f[v] || f[v] > u) {
			f[v] = u;
			dfs(v, fa);
		}
	}
}
int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1, u, v; i <= m; ++i) {
		scanf("%d%d", &u, &v);
		g[v].pb(u);
	}
	for (int i = 1, x, y, z; i <= q; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		Q[y].pb(data(x, z, i));
	}
	for (int i = 1; i <= n; ++i) 
		if (Q[i].size()) {
			memset(f, 0, sizeof(f));
			dfs(i, i);
			for (int j = 1; j <= n; ++j)	st[0][j] = f[j];
			for (int j = 1; j <= 12; ++j)
				for (int k = 1; k <= n; ++k)	
					st[j][k] = st[j - 1][st[j - 1][k]];
			for (auto& now : Q[i]) {
				int v = now.t, cnt = now.k - 1, id = now.id;
				if (!f[v] || st[12][v]) {
					ans[id] = -1;
					continue;
				}
				for (int j = 0; j <= 12; ++j)
					if (cnt >> j & 1) v = st[j][v];
				ans[id] = v ? v : -1;
			}
		}
	for (int i = 1; i <= q; ++i)	printf("%d\n", ans[i]);
	return 0;
}
