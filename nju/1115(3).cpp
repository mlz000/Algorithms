#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1005;
int n, m, ind, scccnt, scc[N], dfn[N], low[N], du[N];
stack<int> s;
vector<int> g[N];
bool in[N];
void init() {
    ind = scccnt = 0;
    for (int i = 1; i <= n; ++i) g[i].clear(), scc[n] = in[i] = du[i] = dfn[i] = low[i] = 0;
}
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++ind;
	in[u] = 1;
	s.push(u);
    for (int i = 0, v; i < g[u].size(); ++i) {
        v = g[u][i];
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (dfn[v] < dfn[u] && v != fa) low[u] = min(low[u], dfn[v]);
    }
	if (dfn[u] == low[u]) {
		++scccnt;
		int x;
		do {
			x = s.top();
			in[x] = 0;
			scc[x] = scccnt;
			s.pop();
		}while(x != u);
	}
}
int main() {
    while (~scanf("%d%d", &n, &m)) {
        init();
        for (int i = 1, x, y; i <= m; ++i) {
            scanf("%d%d", &x, &y);
            g[x].pb(y);
            g[y].pb(x);
        }
        for (int i = 1; i <= n; ++i) 
            if (!dfn[i])    tarjan(i, -1);
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 0, v; j < g[i].size(); ++j) {
                v = g[i][j];
                if (scc[i] != scc[v])   ++du[scc[i]];       
            }
        for (int i = 1; i <= n; ++i)
            if (du[i] == 1) ++ans;
        printf("%d\n", (ans + 1) >> 1);
    }
    return 0;
}
