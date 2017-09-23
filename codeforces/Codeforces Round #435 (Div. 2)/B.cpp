#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long LL;
const int N = 1e5 + 5;
vector<int> g[N];
int l;
void dfs(int u, int fa, int co) {
	if (!co)	++l;
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i];
		if (v == fa)	continue;
		dfs(v, u, co ^ 1);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		g[u].pb(v), g[v].pb(u);
	}
	dfs(1, 0, 0);
	printf("%I64d\n", (LL)l * (n - l) - n + 1);
	return 0;
}
