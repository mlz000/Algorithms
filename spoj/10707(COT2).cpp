#include <bits/stdc++.h>//Ê÷ÉÏÄª¶Ó COT2
using namespace std;
const int N = 40005, M = 100005;
int now, S, tot, cnt, cnt2, blo[N << 1], to[N << 1], nxt[N << 1], head[N], a[N], b[N], sum[N], l[N], r[N], dfn[N], dep[N], idx[N << 1], p[N][20], ans[M];
bool vis[N];
struct data {
	int id, l, r;
}Q[M];
bool cmp(const data &p, const data &q) {
	return blo[p.l] < blo[q.l] || (blo[p.l] == blo[q.l] && p.r < q.r);
}
void add(int u, int v) {
	to[tot] = v, nxt[tot] = head[u], head[u] = tot++;
	to[tot] = u, nxt[tot] = head[v], head[v] = tot++;
}
inline int readint() {
	char c;
	while (c = getchar(), c < '0' || c > '9');
	int t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	return t;
}
void dfs(int u, int fa) {
	dfn[u] = ++cnt, l[u] = ++cnt2, idx[cnt2] = u, dep[u] = dep[fa] + 1, p[u][0] = fa;
	for (int i = 1; i <= 17; ++i)	p[u][i] = p[p[u][i - 1]][i - 1];
	for (int i = head[u], v; ~i; i = nxt[i]) {
		if (!dfn[v = to[i]]) dfs(v, u);
	}
	r[u] = ++cnt2, idx[cnt2] = u;
}
inline int lca(int u, int v) {
	if (dep[u] > dep[v])	swap(u, v);
	if (dep[u] < dep[v]) {
		int del = dep[v] - dep[u];
		for (int i = 0; i <= 17; ++i) {
			if (del >> i & 1)	v = p[v][i];
		}
	}
	if (u != v) {
		for (int i = 17; i >= 0; --i) {
			if (p[u][i] != p[v][i]) {
				u = p[u][i];
				v = p[v][i];
			}
		}
		u = p[u][0], v = p[v][0];
	}
	return u;
}
void gao(int x) {
	if (vis[x]) {
		if (!(--sum[a[x]]))	--now;
	}
	else if ((++sum[a[x]]) == 1)	++now;
	vis[x] ^= 1;	
}
int main() {
	memset(head, -1, sizeof(head));
	int n = readint(), m = readint();
	for (int i = 1; i <= n; ++i)	a[i] = b[i] = readint();
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; ++i)	a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b; 
	for (int i = 1, x, y; i < n; ++i) {
		x = readint(), y = readint();
		add(x, y);
	}
	dfs(1, 1);
	S = sqrt(cnt2);
	for (int i = 1; i <= cnt2; ++i)	blo[i] = (i - 1) / S + 1;
	for (int i = 1, x, y; i <= m; ++i) {
		x = readint(), y = readint();
		if (dfn[x] > dfn[y])	swap(x, y);
		int t = lca(x, y);
		if (t == x)	Q[i].l = l[x], Q[i].r = l[y];
		else Q[i].l = r[x], Q[i].r = l[y];
		Q[i].id = i;
	}
	sort(Q + 1, Q + m + 1, cmp);
	int L = 1, R = 0;
	for (int i = 1; i <= m; ++i) {
		while (L > Q[i].l)	gao(idx[--L]);
		while (L < Q[i].l)	gao(idx[L++]);
		while (R < Q[i].r)	gao(idx[++R]);
		while (R > Q[i].r)	gao(idx[R--]);
		int u = idx[L], v = idx[R];
		int t = lca(u, v);
		if (t != u && t != v)	gao(t);
		ans[Q[i].id] = now;
		if (t != u && t != v)	gao(t);
	}
	for (int i = 1; i <= m; ++i)	printf("%d\n", ans[i]);
	return 0;
}
