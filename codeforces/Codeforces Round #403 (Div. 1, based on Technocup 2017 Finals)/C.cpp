#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define pb push_back
int now, sz;
vector<int> g[N], ans[N];
bool vis[N];
void dfs(int u) {
	vis[u] = 1;
	if (ans[now].size() < sz)	ans[now].pb(u);
	else ans[++now].pb(u);
	for (auto v : g[u]) {
		if (!vis[v]) {
			dfs(v);
			if (ans[now].size() < sz)	ans[now].pb(u);
			else ans[++now].pb(u);
		}
	}
}
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1, u, v; i <= m; ++i) {
		scanf("%d%d", &u, &v);
		g[u].pb(v), g[v].pb(u);
	}
	sz = (2 * n + k - 1) / k;
	dfs(1);
	for (int i = 0; i < k; ++i) {
		if (i <= now) {
			printf("%d ", ans[i].size());
			for (auto j : ans[i])	printf("%d ", j);
			puts("");
		}
		else printf("1 1\n");
	}
	return 0;
}

