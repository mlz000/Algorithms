#include <bits/stdc++.h>
using namespace std;
const int N = 405;
int f[N];
double x[N], y[N], dis[N][N];
struct data {
	double x, y;
}a[N];
struct edge {
	int u, v;
	double d;
}g[N * N];
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
bool cmp(const edge &p, const edge &q) {
	return p.d < q.d;
}
int main() {
	int n, T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)	scanf("%lf%lf", &a[i].x, &a[i].y), f[i] = i;
		int tot = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = i + 1; j <= n; ++j) {
				g[++tot].d = (a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y);
				g[tot].u = i, g[tot].v = j;
			}
		sort(g + 1, g + tot + 1, cmp);
		for (int i = 1; i <= tot; ++i) {
			int u = g[i].u, v = g[i].v;
			int fu = find(u), fv = find(v);
			if (fu != fv) {
				printf("%d %d\n", u, v);
				f[fu] = fv;
			}
		}
	}
	return 0;
}
