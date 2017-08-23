#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1005;
vector<int> g[N];
int n, b, cnt, top, be[N], sta[N], ans[N];
inline int getInt() {
	char c;
	while (c = getchar(), c < '0' || c > '9');
	int t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	return t;
}
void dfs(int u, int fa) {
	int bot = top;
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i];
		if (v != fa)	dfs(v, u);
		if (top - bot >= b) {
			ans[++cnt] = u;
			while (top != bot)	be[sta[top--]] = cnt; 
		}
	}
	sta[++top] = u;
}
int main() {
	n = getInt(), b = getInt();
	for (int i = 1, x, y; i < n; ++i) {
		x = getInt(), y = getInt();
		g[x].pb(y), g[y].pb(x);
	}
	dfs(1, 0);
	while (top)	be[sta[top--]] = cnt;
	printf("%d\n", cnt);
	for (int i = 1; i <= n; ++i)	printf("%d ", be[i]);
	puts("");
	for (int i = 1; i <= cnt; ++i)	printf("%d ", ans[i]);
	return 0;
}
