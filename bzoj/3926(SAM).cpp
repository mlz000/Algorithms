#include <bits/stdc++.h>
using namespace std;
const int N = 100005 * 2 * 20, M = 10;
typedef long long LL;
#define pb push_back
struct SAM {
	int tot, last, step[N], g[N], par[N], son[N][M], cnt[N], Q[N], ch[N], f[N];
	void init() {
		tot = 0;
		memset(par, 0, sizeof(par));
		par[0] = -1;
		memset(son, 0, sizeof(son));
	}
	int add(int last, int x) {
		int p = last, np = ++tot;
		step[np] = step[p] + 1, last = np, ++g[np];//right
		ch[np] = x;
		for (; !son[p][x] && ~p; p = par[p])	son[p][x] = np;
		if (p == -1)	return np;
		int q = son[p][x];
		if (step[q] == step[p] + 1)	par[np] = q;
		else {
			step[++tot] = step[p] + 1;
			ch[tot] = x;
			int nq = tot;
			memcpy(son[nq], son[q], sizeof(son[q]));
			par[nq] = par[q];
			par[np] = par[q] = nq;
			for (; son[p][x] == q && ~p; p = par[p])	son[p][x] = nq;
		}
		return np;
	}
	void topo() {
		for (int i = 1; i <= tot; ++i)    ++cnt[step[i]];
		for (int i = 1; i <= tot; ++i)    cnt[i] += cnt[i - 1];
		for (int i = 1; i <= tot; ++i)    Q[cnt[step[i]]--] = i;		
	}
	LL gao() {
		LL ans = 0;
		for (int i = 1; i <= tot; ++i)	ans += step[i] - step[par[i]];//i状态表示多少个字符串
		return ans;
	}
}S;
int a[100005], d[100005];
vector<int> g[100005];
void dfs(int u, int fa, int last) {
	int t = S.add(last, a[u]);
	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if (v == fa)	continue;
		dfs(v, u, t);
	}
}
int main() {
	S.init();
	int n, c;
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
	for (int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		g[u].pb(v), g[v].pb(u);
		++d[u], ++d[v];
	}
	for (int i = 1; i <= n; ++i)
		if (d[i] == 1)	dfs(i, 0, 0);
	printf("%lld\n", S.gao());
	return 0;
}
