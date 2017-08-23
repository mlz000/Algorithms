#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 105, inf = 1 << 30;
int id[N], pre[N], vis[N];
double x[N], y[N], in[N];
int n, m;
struct data {
	int u, v;
	double dis;
}e[N * N];
inline double D(int i, int j) {
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}
double MST(int root) {
	double t = 0.0;
	while (1) {
		for (int i = 1; i <= n; ++i)	in[i] = inf;
		for (int i = 1; i <= m; ++i) {
			int u = e[i].u;
			int v = e[i].v;
			if (e[i].dis < in[v] && u != v) {
				pre[v] = u;
				in[v] = e[i].dis;
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (i == root)	continue;
			if (in[i] == inf)	return -1;
		}
		//find cycle
		int cnt = 0;
		memset(id, -1 ,sizeof(id));
		memset(vis, -1 ,sizeof(vis));
		in[root] = 0;
		for (int i = 1; i <= n; ++i) {
			t += in[i];
			int v = i;
			while (vis[v] != i && id[v] == -1 && v != root) {
				vis[v] = i;
				v = pre[v];
			}
			if (v != root && id[v] == -1) {
				for (int u = pre[v]; u != v; u = pre[u])	id[u] = ++cnt;
				id[v] = cnt;
			}
		}
		if (!cnt)	break;//no cycle
		for (int i = 1; i <= n; ++i)
			if (id[i] == -1)	id[i] = ++cnt;
		for (int i = 1; i <= m; ++i) {
			int v = e[i].v;
			e[i].u = id[e[i].u];
			e[i].v = id[e[i].v];
			if (e[i].u != e[i].v)	e[i].dis -= in[v];
		}
		n = cnt;
		root = id[root];
	}
	return t;
}
int main () {
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 1; i <= n; ++i)	scanf("%lf%lf", &x[i], &y[i]);
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d", &e[i].u, &e[i].v);
			if (e[i].u != e[i].v)	e[i].dis = D(e[i].u, e[i].v);
			else e[i].dis = inf;
		}
		double ans = MST(1);
		if (ans == -1)	puts("poor snoopy");
		else printf("%.2lf\n", ans);
	}
	return 0;
}
