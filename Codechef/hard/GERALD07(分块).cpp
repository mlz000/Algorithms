#include <bits/stdc++.h>//好题!分块，并且要要恢复并查集
using namespace std;
const int N = 200005;
int sz, tot, f[N], g[N], ans[N];
struct data {
	int l, r, id;
}q[N];
struct Edge {
	int u, v;
}e[N];
bool cmp(const data &p, const data &q) {
	return p.l / sz < q.l / sz || (p.l / sz == q.l / sz && p.r < q.r);
}
int find(int x) {
	return f[x] == x ? g[x] = x : f[x] = g[x] = find(f[x]);
}
int get(int x) {
	return g[x] == x ? x : g[x] = get(g[x]);
}
int main() {
	int T, n, m, Q;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &m, &Q);
		sz = sqrt(m);
		for (int i = 0; i < m; ++i)	scanf("%d%d", &e[i].u, &e[i].v), --e[i].u, --e[i].v;
		for (int i = 0; i < Q; ++i) {
			scanf("%d%d", &q[i].l, &q[i].r);
			--q[i].l, --q[i].r;
			q[i].id = i;
		}
		sort(q, q + Q, cmp);
		int L = 100000, R = -1;
		for (int i = 0; i < Q; ++i) {
			if (q[i].l / sz != L / sz) {
				for (int i = 0; i < n; ++i)	f[i] = g[i] = i;
				tot = n;
				R = -1;
			}
			int lim = (q[i].l / sz + 1) * sz;
			for (int j = max(lim, R + 1); j <= q[i].r; ++j) {
				int u = e[j].u, v = e[j].v;
				u = find(u), v = find(v);
				if (u != v) {
					--tot;
					f[u] = g[u] = v;
				}
			}
			int now = tot;
			for (int j = q[i].l; j <= min(lim - 1, q[i].r); ++j) {
				int u = e[j].u, v= e[j].v;
				u = get(u), v = get(v);
				if (u != v) {
					--tot;
					g[u] = v;
				}
			}
			for (int j = q[i].l; j <= min(lim - 1, q[i].r); ++j) {
				int u = e[j].u, v = e[j].v;
				find(u), find(v);
			}
			L = q[i].l, R = q[i].r;
			ans[q[i].id] = tot;
			tot = now;
		}
		for (int i = 0; i < Q; ++i)	printf("%d\n", ans[i]);
	}
	return 0;
}
