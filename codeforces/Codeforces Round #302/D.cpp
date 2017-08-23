#include <bits/stdc++.h>
using namespace std;
const int N = 200005, M = (int)1e9 + 7;
#define pb push_back
vector<int> g[N], gg[N];
typedef long long LL;
LL f[N], ff[N], l[N], r[N];
void dfs(int u, int fa) {
	f[u] = 1;
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i];
		if (v == fa)	continue;
		gg[u].pb(v);
		dfs(v, u);
		(f[u] *= (f[v] + 1)) %= M;
	}
}
void dfs2(int u, int fa) {
	l[0] = 1;
	for (int i = 0, v; i < gg[u].size(); ++i) {
		v = gg[u][i];
		l[i + 1] = l[i] * (f[v] + 1) % M;	
	}
	r[gg[u].size() - 1] = 1;
	for (int i = gg[u].size() - 2, v; i >= 0; --i) {
		v = gg[u][i + 1];
		r[i] = r[i + 1] * (f[v] + 1) %  M;
	}
	for (int i = 0, v; i < gg[u].size(); ++i) {
		v = gg[u][i];
		ff[v] = (ff[u] + 1) * l[i] % M * r[i] % M;
	}
	for (int i = 0, v; i < gg[u].size(); ++i) {
		v = gg[u][i];
		dfs2(v, u);
	}
} 
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 2, x; i <= n; ++i) {
		scanf("%d", &x);
		g[x].pb(i), g[i].pb(x);
	}
	dfs(1, 0);
	ff[1] = 0;
	dfs2(1, 0);
	for (int i = 1; i <= n; ++i)	printf("%I64d ", f[i] * (ff[i] + 1) % M);
	return 0;
}
