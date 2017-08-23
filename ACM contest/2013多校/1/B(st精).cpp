#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5 + 10, M = 1e9 + 7;
typedef long long LL;
#pragma comment(linker, "/STACK:1024000000,1024000000") 
#define pb push_back
#define mp make_pair
#define F first
#define S second
inline void read(int &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
char s[5];
int n, m, cnt, ind, mxdep, a[N], Log[N], sum[N], ch[N][26], dfn[N], Rank[N], rRank[N], mx[N], label[N], dep[N], st[20][N], tail[N];
LL p[N], Hash[N];
vector<int> h[N];
vector<pair<int, int> > g[N];
void bfs() {
	queue<int> q;
	memset(dep, 0, sizeof(dep));
	dep[1] = 1;
	label[1] = 0;
	q.push(1);
	int sz = 1;
	memset(ch, 0, sizeof(ch));
	while (q.size()) {
		int x = q.front();
		q.pop();
		int u = label[x];
		for (int i = 0, v; i < g[x].size(); ++i) {
			v = g[x][i].F;
			if (dep[v])	continue;
			if (!ch[u][g[x][i].S])	ch[u][g[x][i].S] = sz++;
			label[v] = ch[u][g[x][i].S];
			dep[v] = dep[x] + 1;
			mxdep = max(mxdep, dep[v]);
			q.push(v);
		}
	}
}
void getRank(int u) {
	rRank[u] = ++cnt;
	for (int i = 0; i < 26; ++i)
		if (ch[u][i])	getRank(ch[u][i]);
}
void dfs(int u, int fa) {
	dfn[u] = ++ind;
	mx[u] = u;
	tail[u] = 0;
	Rank[u] = rRank[label[u]];
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i].F;
		if (v == fa)	continue;
		Hash[v] = (Hash[u] * 26 % M + g[u][i].S) % M;
		dfs(v, u);
		tail[u] = max(tail[u], tail[v] + 1);
		if (dfn[mx[v]] > dfn[mx[u]])	mx[u] = mx[v];
	}
	h[dep[u]].pb(u);
}
void init() {
	int cnt = 0;
	sum[0] = 0;
	for (int i = 1; i <= mxdep; ++i) {
		int sz = h[i].size();
		for (int j = 0; j < sz; ++j)	a[++cnt] = h[i][j];
		sum[i] = sum[i - 1] + sz;
	}
	for (int i = 1; i <= n; ++i)	st[0][i] = a[i];
	for (int i = 1; (1 << i) <= n; ++i)
		for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
			if (Rank[st[i - 1][j]] > Rank[st[i - 1][j + (1 << (i - 1))]])	st[i][j] = st[i - 1][j];
			else st[i][j] = st[i - 1][j + (1 << (i - 1))];
		}
}
bool cmp(const int &a, const int &b) {
	return dfn[a] < dfn[b];
}
void gao() {
	scanf("%d", &m);
	while (m--) {
		int u, d, dd;
		scanf("%d%d", &u, &dd);
		if (dd > tail[u])	puts("IMPOSSIBLE");
		else {
			d = dep[u] + dd;
			int l = lower_bound(h[d].begin(), h[d].end(), u, cmp) - h[d].begin() + 1 + sum[d - 1];
			int r = upper_bound(h[d].begin(), h[d].end(), mx[u], cmp) - h[d].begin() + sum[d - 1];
			int len = Log[r - l + 1];
			int t;
			if (Rank[st[len][l]] > Rank[st[len][r - (1 << len) + 1]])	t = st[len][l];
			else t = st[len][r - (1 << len) + 1];
			printf("%d\n", (Hash[t] - Hash[u] * p[dd] % M + M) % M);
		}
	}
}
int main() {
	int T;
	scanf("%d", &T);
	p[0] = 1;
	for (int i = 1; i <= 1e5; ++i)	p[i] = p[i - 1] * 26 % M;
	for(int i = 1, j = 1, k = -1; i <= (int)1e5; ++i) {
		if (i == j)   Log[i] = ++k, j <<= 1;
		else Log[i] = k;
	}	
	while (T--) {
		memset(tail, 0, sizeof(tail));
		memset(dfn, 0, sizeof(dfn));
		scanf("%d", &n);
		mxdep = cnt = ind = 0;
		for (int i = 1; i <= n; ++i)	g[i].clear(), h[i].clear();
		for (int i = 1, x, y; i < n; ++i) {
			read(x), read(y), scanf("%s", s);
			g[x].pb(mp(y, s[0] - 'a')), g[y].pb(mp(x, s[0] - 'a'));
		}
		bfs();
		getRank(0);
		dfs(1, 0);
		init();
		gao();
	}
	return 0;
}
