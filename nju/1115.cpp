#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 105;
int n, m, ind, scccnt, dfn[N], low[N], scc[N], in[N], out[N];
stack<int> s;
vector<int> g[N];
void init() {
	ind = scccnt = 0;
	for (int i = 1; i <= n; ++i)	g[i].clear(), in[i] = out[i] = scc[i] = 0;
}
void tarjan(int u) {
	dfn[u] = low[u] = ++ind;
	s.push(u);
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i];
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (!scc[v])	low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		++scccnt;
		int x;
		do{
			x = s.top();
			scc[x] = scccnt;
			s.pop();
		}while (x != u);
	}
}
int main() {
	while (~scanf("%d", &n)) {
		init();
		for (int i = 1, x; i <= n; ++i) {
			while (scanf("%d", &x) && x)	g[i].pb(x);
		}
		for (int i = 1; i <= n; ++i) 
			if (!dfn[i])	tarjan(i);
		for (int i = 1; i <= n; ++i) 
			for (int j = 0, v; j < g[i].size(); ++j) {
				v = g[i][j];
				if (scc[i] != scc[v])	++in[scc[v]], ++out[scc[i]];	
			}
		int c1 = 0, c2 = 0;
		for (int i = 1; i <= scccnt; ++i) {
			if (!in[i])	++c1;
			if (!out[i])	++c2;
		}
		if (scccnt == 1)	puts("1"), puts("0");
		else printf("%d\n%d\n", c1, max(c1, c2));
	}
	return 0;
}
