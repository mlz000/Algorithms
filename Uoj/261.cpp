#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 300000;
vector<int> g[N];
vector<int> G[N][2][2];//0/1 up/down 0/1 +/-
int n, m, w[N], dep[N], ans[N], f[N][20], A[N * 2], B[N * 2];
void add(int p, int x, int y, int z) {
	G[x][p][0].pb(z);//+
	if (y != 1)	G[f[y][0]][p][1].pb(z);//-
}
int lca(int x,int y){
	if(dep[x] > dep[y])	swap(x, y);
	if(dep[x] < dep[y]) {
		int delta = dep[y] - dep[x];
		for(int i = 0; i < 20; ++i){
			if(delta >> i & 1)	y = f[y][i];
		}
	}
	if(x != y){
		for (int i = 19; i >= 0; --i){
			if (f[x][i] != f[y][i]){
				x = f[x][i];
				y = f[y][i];
			}
		}
		x = f[x][0], y = f[y][0];
	}
	return x;
}
void dfs(int u) {
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i];
		if (v == f[u][0])	continue;
		f[v][0] = u;
		for (int j = 1; j <= 19; ++j)	f[v][j] = f[f[v][j - 1]][j - 1];
		dep[v] = dep[u] + 1;
		dfs(v);
	}
}
void dfs2(int u) {
	ans[u] -= A[w[u] + dep[u]] + B[w[u] - dep[u] + N];
	for (int i = 0, v; i < G[u][0][0].size(); ++i) {
		v = G[u][0][0][i];
		++A[v];
	}
	for (int i = 0, v; i < G[u][0][1].size(); ++i) {
		v = G[u][0][1][i];
		--A[v];
	}
	for (int i = 0, v; i < G[u][1][0].size(); ++i) {
		v = G[u][1][0][i];
		++B[v + N];
	}
	for (int i = 0, v; i < G[u][1][1].size(); ++i) {
		v = G[u][1][1][i];
		--B[v + N];
	}
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i];
		if (v != f[u][0])	dfs2(v);
	}
	ans[u] += A[w[u] + dep[u]] + B[w[u] - dep[u] + N];
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0, x, y; i < n - 1; ++i) {
		scanf("%d%d", &x, &y);
		g[x].pb(y), g[y].pb(x);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i)	scanf("%d", &w[i]);
	for (int i = 1, x, y, z; i <= m; ++i) {
		scanf("%d%d", &x, &y);
		z = lca(x, y);
		if (dep[z] + w[z] == dep[x])	--ans[z];
		add(0, x, z, dep[x]), add(1, y, z, dep[x] - 2 * dep[z]);
	}
	dfs2(1);
	for (int i = 1; i <= n; ++i)	printf("%d ", ans[i]);
	return 0;
}
