//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
using namespace std;
const int N = 10005;
int n, k, tot, cnt, ans, root, size, f[N], sz[N], dis[N], head[N], nxt[N << 1], to[N << 1], w[N << 1];
bool vis[N];
void add(int u, int v, int c) {
	to[tot] = v, w[tot] = c, nxt[tot] = head[u], head[u] = tot++;
	to[tot] = u, w[tot] = c, nxt[tot] = head[v], head[v] = tot++;
}
void getroot(int u, int fa) {
	f[u] = 0, sz[u] = 1;
	for (int i = head[u], v; ~i; i = nxt[i]) {
		v = to[i];
		if (v != fa && !vis[v]) {
			getroot(v, u);
			sz[u] += sz[v];
			f[u] = max(f[u], sz[v]);
		}
	}
	f[u] = max(f[u], size - sz[u]);
	if (f[u] < f[root])	root = u;
}
void dfs2(int u, int fa, int d) {
	dis[++cnt] = d;
	for (int i = head[u], v; ~i; i = nxt[i]) {
		v = to[i];
		if (v != fa && !vis[v])	dfs2(v, u, d + w[i]);
	}
}
int calc(int u, int d) {
	int t = 0;
	cnt = 0;
	dfs2(u, 0, d);
	sort(dis + 1, dis + cnt + 1);
	int l = 1, r = cnt;
	while (l < r) {
		while (dis[l] + dis[r] > k && l < r)	--r;
		t += r - l;
		++l;
	}
	return t;
}
void dfs(int u) {
	f[root = 0] = size;
	getroot(u, 0);
	ans += calc(root, 0);
	vis[root] = 1;
	for (int i = head[root], v; ~i; i = nxt[i]) {
		v = to[i];
		if (!vis[v]) {
			ans -= calc(v, w[i]);
			size = sz[v];
			dfs(v);
		}
	}
}
int main() {
	while (scanf("%d%d", &n, &k)) {
		if (!n && !k)	break;
		memset(head, -1, sizeof(head));
		memset(vis, 0, sizeof(vis));
		memset(sz, 0, sizeof(sz));
		ans = tot = 0;
		size = n;
		for (int i = 1, x, y, z; i < n; ++i) {
			scanf("%d%d%d", &x, &y, &z);
			add(x, y, z);
		}
		dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}
