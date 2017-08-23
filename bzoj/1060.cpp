#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500005;
#define pb push_back
#define mp make_pair
#define F first
#define S second
vector<pair<int, int> > g[N];
int n, s, f[N];
LL ans;
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
void dfs(int u, int fa) {
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i].F;
		if (v == fa)	continue;
		dfs(v, u);
		f[u] = max(f[u], f[v] + g[u][i].S); 
	}
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i].F;
		if (v == fa)	continue;
		ans += f[u] - f[v] - g[u][i].S; 
	}
}
int main() {
	read(n), read(s);
	for (int i = 1, x, y, z; i < n; ++i) {
		read(x), read(y), read(z);
		g[x].pb(mp(y, z)), g[y].pb(mp(x, z));
	}
	dfs(s, 0);
	printf("%lld\n", ans);
	return 0;
}
