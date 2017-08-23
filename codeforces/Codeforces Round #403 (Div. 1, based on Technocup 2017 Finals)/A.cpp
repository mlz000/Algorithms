#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 2e5 + 5;
vector<int> g[N];
int col[N], cnt, mx;
void dfs(int u, int fa, int c, int fc) {
	col[u] = c;
	mx = max(mx, c);
	int cnt = 1;
	for (auto v : g[u]) {
		if (v != fa) {
			while (cnt == fc || cnt == c)	++cnt;
			dfs(v, u, cnt, c);
			++cnt;
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		g[u].pb(v), g[v].pb(u);
	}
	dfs(1, 0, 1, 0);
	printf("%d\n", mx);
	for (int i = 1; i <= n; ++i)	printf("%d ", col[i]);
	return 0;
}

