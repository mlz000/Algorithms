#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
#define pb push_back
typedef long long LL;
vector<int> g[N];
int n, a[N];
LL sum, lcm = 1ll, now = (LL)1e15;
void dfs(int u, int fa, long long d) {
	lcm = lcm /__gcd(lcm, d) * d;
	if (d > sum || d < 0) {
		printf("%I64d\n", sum);
		exit(0);
	}
	if (g[u].size() == 1 && u != 1)	now = min(now, d * a[u]);
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i];
		if (v == fa)	continue;
		dfs(v, u, d * (g[u].size() - (u != 1)));
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]), sum += a[i];
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1, 0, 1);
	printf("%I64d\n", sum - now / lcm * lcm);
	return 0;
}
