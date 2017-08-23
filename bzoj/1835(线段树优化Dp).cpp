#include <bits/stdc++.h>
using namespace std;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
const int N = 20005, inf = ~0u >> 1;
int ans, n, m, d[N], c[N], s[N], w[N], st[N], ed[N], f[N];
int lazy[N << 2], v[N << 2];
vector<int> g[N];
inline int read(int &t) {
	char c;
	while (c = getchar(), c < '0' || c > '9');
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	return t;
}
void pushdown(int rt) {
	if (lazy[rt]) {
		lazy[ls] += lazy[rt], lazy[rs] += lazy[rt];
		v[ls] += lazy[rt], v[rs] += lazy[rt];
		lazy[rt] = 0;
	}
}
inline void pushup(int rt) {
	v[rt] = min(v[ls], v[rs]);
}
void build(int rt, int l, int r) {
	lazy[rt] = 0;
	if (l == r) {
		v[rt] = f[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(rt);
}
void change(int rt, int l, int r, int L, int R, int x) {
	if (L > R)	return;
	if (L <= l && R >= r) {
		lazy[rt] += x;
		v[rt] += x;
		return;
	}
	pushdown(rt);
	int mid = l + r >> 1;
	if (L <= mid)	change(ls, l, mid, L, R, x);
	if (R > mid)	change(rs, mid + 1, r, L, R, x);
	pushup(rt);
}
int ask(int rt, int l, int r, int L, int R) {
	if (L > R)	return 0;
	if (L <= l && R >= r)	return v[rt];
	int mid = l + r >> 1;
	pushdown(rt);
	int t = inf;
	if (L <= mid)	t = min(t, ask(ls, l, mid, L, R));
	if (R > mid)	t = min(t, ask(rs, mid + 1, r, L, R));
	return t;
}
void init() {
	read(n), read(m);
	for (int i = 2; i <= n; ++i)	read(d[i]);
	for (int i = 1; i <= n; ++i)	read(c[i]);
	for (int i = 1; i <= n; ++i)	read(s[i]);
	for (int i = 1; i <= n; ++i)	read(w[i]);
	d[++n] = inf, w[n] = inf, ++m;
	for (int i = 1; i <= n; ++i) {
		st[i] = lower_bound(d + 1, d + n + 1, d[i] - s[i]) - d;
		ed[i] = lower_bound(d + 1, d + n + 1, d[i] + s[i]) - d;
		if (d[ed[i]] > d[i] + s[i])	--ed[i];
		g[ed[i]].push_back(i);
	}
}
void gao() {
	ans = inf;
	for (int i = 1; i <= m; ++i) {
		if (i == 1) {
			int t = 0;
			for (int j = 1; j <= n; ++j) {
				f[j] = t + c[j];
				for (int k = 0; k < g[j].size(); ++k) {
					int x = g[j][k];
					t += w[x];
				}
			}
			ans = f[n];
			continue;
		}
		build(1, 1, n);
		for (int j = 1; j <= n; ++j) {
			f[j] = ask(1, 1, n, 1, j - 1) + c[j];
			for (int k = 0; k < g[j].size(); ++k) {
				int x = g[j][k];
				change(1, 1, n, 1, st[x] - 1, w[x]);
			}
		}
		ans = min(ans, f[n]);
	}
}
int main() {
	init();
	gao();
	printf("%d\n", ans);
	return 0;
}
