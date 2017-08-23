#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 10005, LOG = 18;
int f[N], dep[N], dis[N], p[N][20];
vector<int> g[N], g2[105];
void dfs(int u, int fa, int d) {
	dep[u] = dep[fa] + 1;
	dis[u] = d;
	p[u][0] = fa;
	for (int i = 1; i < LOG; ++i)	p[u][i] = p[p[u][i - 1]][i - 1];
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i];
		if (v == fa)	continue;
		dfs(v, u, d + 1);
	}
}
int lca(int x, int y){
	if(dep[x] > dep[y])	swap(x, y);
	if(dep[x] < dep[y]){
		int delta = dep[y] - dep[x];
		for(int i=0; i < LOG; ++i){
			if(delta >> i & 1)	y = p[y][i];
		}
	}
	if(x != y){
		for(int i = LOG - 1; i>= 0; --i){
			if(p[x][i] != p[y][i]){
				x = p[x][i];
				y = p[y][i];
			}
		}
		x = p[x][0];
		y = p[y][0];
	}
	return x;
}
int main() {
	int n, k, b, q, a, p;
	scanf("%d%d%d", &n, &k, &b);
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		g[x].pb(y), g[y].pb(x);
	}
	dfs(b, b, 0);
	for (int i = 1; i <= n; ++i)	scanf("%d", &f[i]), g2[f[i]].pb(i);
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &a, &p);
		int mx = -1, mxi = 0;
		if (g2[p].size() == 0) {
			puts("-1");
			continue;
		}
		for (int i = 0, c, t; i < g2[p].size(); ++i) {
			c = g2[p][i];
			int x = lca(a, c);
			t = dep[x];
			if (t > mx) mx = t, mxi = c;
			else if (t == mx && c < mxi)	mxi = c;
		}
		printf("%d\n", mxi);
	}
	return 0;
}
