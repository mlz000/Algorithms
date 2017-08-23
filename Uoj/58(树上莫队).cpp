#include <bits/stdc++.h>//dfsÐò·Ö¿é
using namespace std;
const int N = 100005;
bool vis[N];
int n, m, q, S, tot, cnt, cnt2, qsz, csz, dep[N], dfn[N], idx[N << 1], l[N], r[N], p[N][20], last[N << 1], block[N << 1], to[N << 1], nxt[N << 1], head[N], c[N];
long long w[N], v[N], s[N], ans[N], sum;
struct data {
	int id, cur, l, r;
}Q[N];
struct data2 {
	int x, ago, now;
}C[N];
inline int getInt() { 
	char ch;
	while (ch = getchar(), ch < '0' || ch > '9');
	int t = ch - '0';
	while (ch = getchar(), ch >= '0' && ch <= '9')	t = t * 10 + ch - '0';
	return t;
}
inline void add(int u, int v) {
	to[tot] = v, nxt[tot] = head[u], head[u] = tot++;
	to[tot] = u, nxt[tot] = head[v], head[v] = tot++;
}
bool cmp(const data &p, const data &q) {
	return block[p.l] < block[q.l] || (block[p.l] == block[q.l] && p.r < q.r) || (block[p.l] == block[q.l] && p.r == q.r && p.cur < q.cur);
}
void dfs(int u, int fa) {
	dfn[u] = ++cnt, idx[++cnt2] = u, l[u] = cnt2, dep[u] = dep[fa] + 1, p[u][0] = fa;
	for (int i = 1; i <= 17; ++i)	p[u][i] = p[p[u][i - 1]][i - 1];
	for (int i = head[u], v; ~i; i = nxt[i]) {
		if (!dfn[v = to[i]]) {
			dfs(v, u);
		}
	}
	idx[++cnt2] = u, r[u] = cnt2;
}
inline int lca(int u, int v) {
	if (dep[u] > dep[v])	swap(u, v);
	if (dep[u] < dep[v]) {
		int del = dep[v] - dep[u];
		for (int i = 0; i <= 17; ++i)
			if (del >> i & 1)	v = p[v][i];
	}
	if (u != v) {
		for (int i = 17; i >= 0; --i) 
			if (p[u][i] != p[v][i]) {
				u = p[u][i];
				v = p[v][i];
			}
		u = p[u][0], v = p[v][0];
	}
	return u;
}
void init() {
	memset(head, -1, sizeof(head));
	n = getInt(), m = getInt(), q = getInt();
	for (int i = 1; i <= m; ++i)	v[i] = getInt();
	for (int i = 1; i <= n; ++i)	w[i] = getInt();
	for (int i = 1; i < n; ++i)	add(getInt(), getInt());
	for (int i = 1; i <= n; ++i)	last[i] = c[i] = getInt();
	dfs(1, 1);
	S = (int)pow(cnt2, 2.0 / 3.0);
	for (int i = 1; i <= cnt2; ++i)	block[i] = (i - 1) / S + 1;
	qsz = 0, csz = 0;
	for (int i = 1; i <= q; ++i) {
		int op = getInt();
		if (op) {
			int a = getInt(), b = getInt();
			if (dfn[a] > dfn[b])	swap(a, b);
			int f = lca(a, b);
			if (f == a)	a = l[a], b = l[b];
			else a = r[a], b = l[b]; 
			Q[++qsz].id = qsz, Q[qsz].cur = csz, Q[qsz].l = a, Q[qsz].r = b;
		}
		else {
			C[++csz].x = getInt();
			C[csz].ago = last[C[csz].x], C[csz].now = last[C[csz].x] = getInt(); 
		}
	}
	sort(Q + 1, Q + qsz + 1, cmp);
}
inline void rev(int x) {
	if (vis[x])	sum -= v[c[x]] * w[s[c[x]]--];
	else sum += v[c[x]] * w[++s[c[x]]];
	vis[x] ^= 1;
}
inline void modify(int x, int col) {
	if (vis[x]) {
		rev(x);
		c[x] = col;
		rev(x);
	}
	else c[x] = col;
}
void solve() {
	int L = 1, R = 0, ct = 1;
	for (int i = 1; i <= qsz; ++i) {
		while (ct <= Q[i].cur) modify(C[ct].x, C[ct].now), ++ct;
		while (ct > Q[i].cur)	modify(C[ct].x, C[ct].ago), --ct;
		while (L > Q[i].l)	rev(idx[--L]);
		while (L < Q[i].l)	rev(idx[L++]);
		while (R < Q[i].r)	rev(idx[++R]);
		while (R > Q[i].r)	rev(idx[R--]);
		int u = idx[L], v = idx[R];
		int l = lca(u,v);
		if (l != u && l != v)	rev(l);
		ans[Q[i].id] = sum;
		if (l != u && l != v)	rev(l);
	}
	for (int i = 1; i <= qsz; ++i)	printf("%lld\n", ans[i]);
}
int main() {
	init();
	solve();
	return 0;
}
