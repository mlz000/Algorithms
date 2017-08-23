#include <bits/stdc++.h>
using namespace std;
const int N = 150;
int n, m, l[N];
bool vis[N], g[N][N];
bool ok(int u) {
	for (int i = 1; i <= n; ++i) 
		if (g[u][i] && !vis[i]) {
			vis[i] = 1;
			if (!l[i] || ok(l[i])) {
				l[i] = u;
				return 1;
			}
		}
	return 0;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(g, 0, sizeof(g));
		memset(l, 0, sizeof(l));
		scanf("%d%d", &n, &m);
		for (int i = 1, u, v; i <= m; ++i) {
			scanf("%d%d", &u, &v);
			g[u][v] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			memset(vis, 0, sizeof(vis));
			if (ok(i))	++ans;
		}
		printf("%d\n", n - ans);
	}
	return 0;
}
