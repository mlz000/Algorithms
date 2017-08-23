#include <cstdio>//Ê÷Á´ÆÊ·Ö+dp
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define pb push_back
#pragma comment(linker, "/STACK:1024000000,1024000000") 
const int N = 100005;
int n, tot, cnt, head[N], to[N << 1], nxt[N << 1], dep[N], pre[N], q[N], sz[N], top[N], son[N], id[N];
int d[N], s[N], treed[N << 2], trees[N << 2];
bool vis[N];
struct Chain {
	int a, b, w;
	Chain(){}
	Chain(int a, int b, int w) : a(a), b(b), w(w){}
};
vector<Chain> a[N];
void init() {
	tot = cnt = 0;
	for (int i = 1; i <= n; ++i)	a[i].clear();
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(sz, 0, sizeof(sz));
    memset(top, 0, sizeof(top));
    memset(son, 0, sizeof(son));
	memset(d, 0, sizeof(d));
	memset(s, 0, sizeof(s));
	memset(trees, 0, sizeof(trees));
	memset(treed, 0, sizeof(treed));
}
void gao() {
	int r = 0;
	vis[dep[1] = q[0] = 1] = 1;
	for (int i = 0; i <= r; ++i)
		for (int j = head[q[i]]; ~j; j = nxt[j]) 
			if (!vis[to[j]]){
				vis[to[j]] = 1;
				dep[q[++r] = to[j]] = dep[q[i]] + 1;
				pre[q[r]] = q[i];
			}
	for (int i = r; i >= 0; --i) {
		sz[pre[q[i]]] += ++sz[q[i]];
		if (sz[son[pre[q[i]]]] < sz[q[i]])	son[pre[q[i]]] = q[i];
	}
	for (int i = 0; i <= r; ++i)
		if (!top[q[i]]) {
			for (int j = q[i]; j; j = son[j]) {
				top[j] = q[i];
				id[j] = ++cnt;
			}
		}
}
void add(int u, int v) {
	to[tot] = v, nxt[tot] = head[u], head[u] = tot++;
	to[tot] = u, nxt[tot] = head[v], head[v] = tot++;
}
int lca(int a, int b) {
	while (1) {
		if (top[a] == top[b])	return dep[a] <= dep[b] ? a : b;
		if (dep[top[a]] < dep[top[b]])	swap(a, b);
		a = pre[top[a]];
	}
}
void add(int rt, int l, int r, int p, int x, int f) {
	if (l == r) {
		if (!f)	trees[rt] = x;
		else treed[rt] = x;
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid)	add(ls, l, mid, p, x, f);
	else add(rs, mid + 1, r, p, x, f);
	if (!f)	trees[rt] = trees[ls] + trees[rs];
	else treed[rt] = treed[ls] + treed[rs];
}
int query(int rt, int l, int r, int L, int R, int f) {
	if (L <= l && R >= r) {
		if (!f)	return trees[rt];
		else return treed[rt];
	}
	int mid = l + r >> 1;
	if (R <= mid)	return query(ls, l, mid, L, R, f);
	else if (L > mid)	return query(rs, mid + 1, r, L, R, f);
	else return query(ls, l, mid, L, R, f) + query(rs, mid + 1, r, L, R, f);
}
int ask(int a, int b, int f) {
	int ans = 0;
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]])	swap(a, b);
		int t = query(1, 1, n, id[top[a]], id[a], f);
		ans += t;
		a = pre[top[a]];
	}
	if (dep[a] < dep[b])	swap(a, b);
	int t = query(1, 1, n, id[b], id[a], f);
	ans += t;
	return ans;
}
void dfs(int u, int fa) {
	for (int i = head[u], v; ~i; i = nxt[i]) {
		v = to[i];
		if (v == fa)	continue;
		dfs(v, u);
		s[u] += d[v];
	}
	add(1, 1, n, id[u], s[u], 0);
	d[u] = s[u];
	for (int j = 0; j < a[u].size(); ++j) {
		Chain t = a[u][j];
		d[u] = max(d[u], t.w + ask(t.a, t.b, 0) - ask(t.a, t.b, 1));
	}
	add(1, 1, n, id[u], d[u], 1);
}
int main() {
	int T;
	read(T);
	while (T--) {
		int m;
		read(n), read(m);
		init();
		for (int i = 1, x, y; i < n; ++i) {
			read(x), read(y);
			add(x, y);
		}
		gao();
		for (int i = 1, x, y, z; i <= m; ++i) {
			read(x), read(y), read(z);
			a[lca(x, y)].pb(Chain(x, y, z));
		}
		dfs(1, 0);
		printf("%d\n", d[1]);
	}
	return 0;
}
