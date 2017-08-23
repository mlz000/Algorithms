#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#pragma comment(linker, "/STACK:1024000000,1024000000") 
typedef long long LL;
const int N = 500005;
vector<int> g[N], gg[N];
pair<int, int> a[N];
int f[N], sz[N], du[N];
bool vis[N];
void dfs(int u) {
	if (f[u])	return;
	if (gg[u].size() == 0) {
		f[u] = 1;
		return;
	}
	for (int i = 0; i < gg[u].size(); ++i) {
		int v = gg[u][i];
		dfs(v);
		f[u] += f[v];
	}
	++f[u];
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		memset(vis, 0, sizeof(vis));
		memset(du, 0, sizeof(du));
		for (int i = 1, x; i <= n; ++i) {
			scanf("%d", &x);
			a[i] = mp(x, i);
		}
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; ++i) {
			g[i].clear();
			gg[i].clear();
			f[i] = 0;
		}
		for (int i = 1, x, y; i < n; ++i) {
			scanf("%d%d", &x, &y);
			g[x].pb(y), g[y].pb(x);
		}
		for (int i = 1; i <= n; ++i) {
			int u = a[i].S;
			for (int j = 0; j < g[u].size(); ++j) {
				int v = g[u][j];
				if (!vis[v])	gg[u].pb(v), ++du[v];
			}
			vis[u] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			if (!du[i]) {
				dfs(i);
				ans = max(ans, f[i]);
			}
		cout << ans << endl;
	}
	return 0;
}
