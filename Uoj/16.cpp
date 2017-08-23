#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2e5 + 5, M = 10007;
int w[N], sum[N];
vector<int> g[N];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		g[u].pb(v), g[v].pb(u);
	}
	for (int i = 1; i <= n; ++i)	scanf("%d", &w[i]);
	int mx = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		int mx1 = 0, mx2 = 0;
		for (int j = 0, v; j < g[i].size(); ++j) {
			v = g[i][j];
			(sum[i] += w[v]) %= M;
			if (w[v] >= mx1)	mx2 = mx1, mx1 = w[v];
			else if (w[v] > mx2)	mx2 = w[v];
		}
		if (mx1 * mx2 > mx)	mx = mx1 * mx2;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 0, v; j < g[i].size(); ++j) {
			v = g[i][j];
			(ans += (M + sum[i] - (w[v] % M)) * w[v] % M) %= M;
		}
	printf("%d %d\n", mx, ans);
	return 0;
}
