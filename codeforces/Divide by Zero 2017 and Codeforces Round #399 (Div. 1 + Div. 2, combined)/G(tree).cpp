#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5 + 5;
vector<int> g[N];
map<int, int> mp[2], p;//p : u to root. mp[0] : out of p. mp[1] : son
int root, n, ans[N], sz[N];
bool big[N];
void dfs(int u) {
	sz[u] = 1, ans[u] = n - 1;
	for (auto v : g[u]) {
		dfs(v);
		sz[u] += sz[v];
	}
	++mp[0][sz[u]];
}
void add(int u, int c) {
	++mp[c][sz[u]];
	if (mp[c ^ 1][sz[u]] == 1)	mp[c ^ 1].erase(sz[u]);
	else --mp[c ^ 1][sz[u]];
	for (auto v : g[u])
		if (!big[v])	add(v, c);
}
void gao(map<int, int> &G, int mx2, int mx1, int mn, int u, int off) {
	int L = mx2, R = mx1;
	while (L < R - 1) {
		int mid = L + R >> 1;
		int cut = mx1 - mid + off;
		auto it = G.lower_bound(cut);
		if (it == G.end())	L = mid;
		else if (it -> first + mn <= mid + off)	R = mid;
		else L = mid;
	}
	ans[u] = min(ans[u], R);
}
void dfs2(int u, bool ok) {
	++p[sz[u]];
	if (mp[0][sz[u]] == 1)	mp[0].erase(sz[u]);
	else --mp[0][sz[u]];
	int ws = -1, mx1 = -1, mx2 = -1, mn = n - 1;
	for (auto v : g[u]) {
		if (sz[v] > mx1)	ws = v, mx2 = mx1, mx1 = sz[v];
		else if (sz[v] == mx1)	mx2 = mx1;
		else mx2 = max(mx2, sz[v]);
		mn = min(mn, sz[v]);
	}
	if (u != root)	mn = min(mn, n - sz[u]);
	for (auto v : g[u])
		if (v != ws)
			dfs2(v, 0);
	if (~ws) big[ws] = 1, dfs2(ws, 1);
	if (mx1 >= n - sz[u]) {	//mx in the tree of u
		mx2 = max(mx2, n - sz[u]);
		gao(mp[1], mx2 - 1, mx1, mn, u, 0);
	}
	++mp[0][sz[u]];
	add(u, 1);
	if (p[sz[u]] == 1)	p.erase(sz[u]);
	else	--p[sz[u]];
	if (n - sz[u] > mx1) {	//mx out of the tree of u
		mx2 = mx1;
		gao(p, mx2 - 1, n - sz[u], mn, u, sz[u]);
		gao(mp[0], mx2 - 1, n - sz[u], mn, u, 0);
	}
	if (~ws)	big[ws] = 0;
	if (!ok)	add(u, 0);
}
int main() {
	scanf("%d", &n);
	for (int i = 1, x, y; i <= n; ++i) {
		scanf("%d%d", &x, &y);
		if (!x)	root = y;
		else g[x].pb(y);
	}
	dfs(root);
	dfs2(root, 1);
	for (int i = 1; i <= n; ++i)	printf("%d\n", ans[i]);
	return 0;
}

