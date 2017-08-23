#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int n, m, l[N];
bool v[N], g[N][N];
bool ok(int u) {
	for (int j = 1; j <= n; ++j) 
		if (g[u][j] && !v[j]) {
			v[j] = 1;
			if (!l[j] || ok(l[j])) {
				l[j] = u;
				return 1;
			}
		}
	return 0;
}
int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(g, 0, sizeof(g));
		memset(l, 0, sizeof(l));
		int ans = 0;
		for (int i = 1, x, y; i <= n; ++i) {
			scanf("%d", &x);
			while (x--) {
				scanf("%d", &y);
				g[i][y] = 1;
			}
		}
		for (int i = 1; i <= n; ++i) {
			memset(v, 0, sizeof(v));
			if (ok(i))	++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
