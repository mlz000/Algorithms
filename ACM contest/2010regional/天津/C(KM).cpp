#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
const int N = 210, inf = (int)1e9;
char s[N][1005];
int ans, tot, S, T, d[N << 1], p[N << 1], head[N << 1], fr[N * N * 2], to[N * N * 2], cap[N * N * 2], w[N * N * 2], nxt[N * N * 2];
bool vis[N << 1];
void add(int u, int v, int f, int cost) {
	fr[tot] = u, to[tot] = v, cap[tot] = f, w[tot] = -cost, nxt[tot] = head[u], head[u] = tot++;
	fr[tot] = v, to[tot] = u, cap[tot] = 0, w[tot] = cost, nxt[tot] = head[v], head[v] = tot++;
}
bool spfa() {
	queue<int> q;
	for (int i = S; i <= T; ++i)	d[i] = inf;
	d[S] = 0, p[S] = -1;
	q.push(S);
	while (q.size()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = head[u], v; ~i; i = nxt[i]) {
			v = to[i];
			if (cap[i] > 0 && d[u] + w[i] < d[v]) {
				d[v] = d[u] + w[i];
				p[v] = i;
				if (!vis[v])	vis[v] = 1, q.push(v);
			}
		}
	}
	return d[T] < inf;
}
void solve() {
	int flow = inf;
	for (int i = p[T]; ~i; i = p[fr[i]])	flow = min(flow, cap[i]);
	for (int i = p[T]; ~i; i = p[fr[i]])	cap[i] -= flow, cap[i ^ 1] += flow;
	ans += d[T] * flow;
}
void init() {
	ans = tot = 0;
	memset(head, -1, sizeof(head));
	memset(vis, 0, sizeof(vis));
	memset(p, 0, sizeof(p));
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		init();
		S = 0, T = n + n + 1;
		for (int i = 1; i <= n; ++i)	scanf("%s", s[i]);
		for (int i = 1; i <= n; ++i)	add(S, i, 1, 0), add(i + n, T, 1, 0);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				if (i == j) {
					add(i, i + n, 1, 0);
					continue;
				}
				int t = 0;
				int l1 = strlen(s[i]);
				int l2 = strlen(s[j]);
				int p1 = l1 - 1, p2 = 0;
				while (p1 >= 0 && p2 < l2 && s[i][p1] == s[j][p2]) {
					++t, --p1, ++p2;
				}
				add(i, j + n, 1, t);
			}
		while (spfa())	solve();
		printf("%d\n", -ans);
	}
	return 0;
}
