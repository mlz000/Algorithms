#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N = 105, M = 10005;
int n, m, f[N];
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
struct data {
	int u, v, w;
}e[M];
bool cmp(const data &p, const data &q) {
	return p.w < q.w;
}
int main() {
	while (scanf("%d", &n) != EOF) {
		int m = 0, q;
		for (int i = 1; i <= n; ++i)
			for (int j = 1, x; j <= n; ++j) {
				scanf("%d", &x);
				if (i >= j)	continue;
				e[++m].u = i;
				e[m].v = j;
				e[m].w = x;
			}
		for (int i = 1; i <= n; ++i)	f[i] = i;
		sort(&e[1], &e[m + 1], cmp);
		scanf("%d",  &q);
		while (q--) {
			int x, y;
			scanf("%d%d", &x, &y);
			int fx = find(x);
			int fy = find(y);
			f[fy] = fx;
		}
		int sum = 0;
		for (int i = 1; i <= m; ++i) {
			int fu = find(e[i].u);
			int fv = find(e[i].v);
			if (fu != fv) {
				f[fu] = fv;
				sum += e[i].w;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
