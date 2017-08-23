#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 105;
int n, m, ind, scccnt, dfn[N], low[N], cut[N];
vector<int> g[N];
void init() {
	ind = 0;
	for (int i = 1; i <= n; ++i)	g[i].clear(), cut[i] = dfn[i] = low[i] = 0;
}
void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++ind;
	int s = 0;
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i];
		if (!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			++s;
			if (low[v] >= dfn[u])	cut[u] = 1;
		}
		else if (dfn[v] < dfn[u] && v != fa)	low[u] = min(low[u], dfn[v]);
	}
	if (fa < 0 && s == 1)	cut[u] = 0;
}
int main() {
	while (~scanf("%d", &n) && n) {
		init();
		int u, v;
		while (scanf("%d", &u) && u) {
			char s[300];
			fgets(s,300,stdin);
			int i = 0;	
			while (s[i] && (!isdigit(s[i])))	++i;
			while (s[i]) {
                v = 0;
                while (isdigit(s[i])) {
                    v = v * 10 + s[i] - '0';
                    ++i;
                }
                g[u].pb(v);
                g[v].pb(u);
                while (s[i] && (!isdigit(s[i]))) ++i;
            }
		}
		for (int i = 1; i <= n; ++i) 
			if (!dfn[i])	tarjan(i, -1);
		int ans = 0;
		for (int i = 1; i <= n; ++i)	ans += cut[i];
		printf("%d\n", ans);
	}
	return 0;
}
