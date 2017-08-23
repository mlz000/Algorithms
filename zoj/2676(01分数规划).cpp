#include <bits/stdc++.h>
using namespace std;
const int N = 105, M = 405 << 1;
const double eps = 1e-6;
int n, m, tot, x[M], y[M], head[N], ret[N], dis[N], sum[N], cur[N], pre[N];
double c[M];
bool vis[N];
struct data {
	int v, next;
	double f;
}e[M << 1];
void add(int u, int v, double f) {
	e[tot].v = v, e[tot].f = f, e[tot].next = head[u], head[u] = tot++;
	e[tot].v = u, e[tot].f = 0.0, e[tot].next = head[v], head[v] = tot++;
}
void init() {
	tot = 0;
	memset(head, -1, sizeof(head));
	memset(dis, 0, sizeof(dis));
	memset(pre, -1, sizeof(pre));
	memset(sum, 0, sizeof(sum));
}
double isap(int st, int ed) {
	sum[0] = n;
	for (int i = 1; i <= n; ++i)	cur[i] = head[i];
	double aug = -1, ans = 0.0;
	int u = pre[st] = st;
	bool flag;
	while (dis[st] < n) {
		flag = 0;
		for (int &i = cur[u]; ~i; i = e[i].next) {
			int v = e[i].v;
			if (e[i].f && dis[u] == dis[v] + 1) {
				flag = 1;
				pre[v] = u;
				u = v;
				aug = (aug == -1) ? e[i].f : min(aug, e[i].f);
				if (v == ed) {
					ans += aug;
					for (u = pre[v]; v != st; v = u, u = pre[u]) {
						e[cur[u]].f -= aug;
						e[cur[u] ^ 1].f += aug;
					}
					aug = -1;
				}
				break;
			}
		}
		if (flag)	continue;
		int Min = n;
		for (int i = head[u]; ~i; i = e[i].next) {
			int v = e[i].v;
			if (e[i].f && dis[v] < Min)	{
				cur[u] = i;
				Min = dis[v];
			}
		}
		if (--sum[dis[u]] == 0)	break;
		dis[u] = Min + 1;
		++sum[dis[u]];
		u = pre[u];
	}
	return ans;
}
bool ok(double xx) {
	init();
	double flow = 0.0;
	for (int i = 1; i <= m; ++i) {
		if (c[i] > xx)	add(x[i], y[i], c[i] - xx), add(y[i], x[i], c[i] - xx);
		else flow += c[i] - xx;
	}
	flow += isap(1, n);
	return flow < eps;
}
void dfs(int u) {
	vis[u] = 1;
	for (int i = head[u]; ~i; i = e[i].next) {
		if (e[i].f && !vis[e[i].v])	dfs(e[i].v);
	}
}
int main() {
	int tt = 0;
	while (~scanf("%d%d", &n, &m)) {
		if (tt++)	puts("");
		memset(vis, 0, sizeof(vis));
		double l = 1e7, r = 0.0;
		for (int i = 1; i <= m; ++i)	scanf("%d%d%lf", &x[i], &y[i], &c[i]), l = min(l, c[i]), r = max(r, c[i]);
		for (int i = 1; i <= 100; ++i) {
			double mid = (l + r) / 2.0;
			if (ok(mid))	r = mid;
			else l = mid;
		}
		dfs(1);
		int cnt = 0;
		for (int i = 1; i <= m; ++i) {
			if (vis[x[i]] + vis[y[i]] == 1 || c[i] <= l)	ret[++cnt] = i;
		}
		printf("%d\n", cnt);
		for (int i = 1; i <= cnt; ++i)	printf("%d ", ret[i]);
		puts("");
	}
	return 0;
}
