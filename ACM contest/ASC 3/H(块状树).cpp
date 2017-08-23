#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
const int N = 10005;
int bot, cnt, n, b, top, be[N], c[N], s[N];
vector<int> g[N];
void dfs(int u, int fa) {
	int bot = top;
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i];
		if (v == fa)	continue;
		dfs(v, u);
		if (top - bot >= b) {	
			++cnt;
			c[cnt] = u;
			while (top != bot)	be[s[top--]] = cnt;
		}
	}
	s[++top] = u;
}
int main() {
	freopen("royal.in", "r", stdin);
	freopen("royal.out", "w", stdout);
	scanf("%d%d", &n, &b);
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		g[x].pb(y), g[y].pb(x);
	}
	dfs(1, 0);
	if (!cnt) {
		++cnt;
		c[cnt] = s[top];
		while (top)	be[s[top--]] = cnt;
	}
	else while (top)	be[s[top--]] = cnt;
	printf("%d\n", cnt);
	for (int i = 1; i <= n; ++i)	printf("%d ", be[i]);
	puts("");
	for (int i = 1; i <= cnt; ++i)	printf("%d ", c[i]);
	return 0;
}
