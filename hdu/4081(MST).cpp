//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
const int N = 1005;
int n, m, tot, f[N], w[N];
double ans, xx, yy;
vector<pair<int, double> > g[N];
struct data {
	double x, y;
	int p;
	data(){}
	data(double x, int y, int p): x(x), y(y), p(p){}
}a[N];
struct data2 {
	int x, y;
	double z;
	data2(){}
	data2(int x, int y, double z): x(x), y(y), z(z){}
}e[N * N];
bool cmp(const data2 &p, const data2 &q) {
	return p.z < q.z;
}
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
inline double sqr(double x) {
	return x * x;
}
inline double dis(int p, int q) {
	return sqrt(sqr(a[p].x - a[q].x) + sqr(a[p].y - a[q].y));
}
void init() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)	scanf("%lf%lf%d", &a[i].x, &a[i].y, &a[i].p);
	for (int i = 1; i <= n; ++i)	g[i].clear();
	tot = 0;
	ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j) {
			double t = dis(i, j);
			e[++tot] = data2(i, j, t);
		}
}
int dfs(int u, int fa, int now) {
	now = max(now, a[u].p);
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i].F;
		if (v == fa)	continue;
		now = max(now, dfs(v, u, now));
	}
	return now;
}
void gao() {
	yy = 0;
	for (int i = 1; i <= n; ++i)	f[i] = i;
	sort(e + 1, e + tot + 1, cmp);
	for (int i = 1; i <= tot; ++i) {
		int fx = find(e[i].x), fy = find(e[i].y);
		if (fx != fy) {
			yy += e[i].z;
			f[fx] = fy;
			g[e[i].x].pb(mp(e[i].y, e[i].z)), g[e[i].y].pb(mp(e[i].x, e[i].z));
		}
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < g[i].size(); ++j) {
			int t1 = dfs(i, g[i][j].F, 0), t2 = dfs(g[i][j].F, i, 0);
			ans = max(ans, (double)(t1 + t2) / (yy - g[i][j].S));
		}
	printf("%.2lf\n", ans);
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		init();
		gao();
	}	
	return 0;
}
