#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N = 105, M = 10005;
int n, m, f[N], path[M];
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
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt){
		scanf("%d%d", &n, &m);
		bool fl = 1;
		for (int i = 1; i <= n; ++i)	f[i] = i;
		for (int i = 1; i <= m; ++i)	scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
		sort(&e[1], &e[m + 1], cmp);
		int sum = 0, cnt = 0;
		for (int i = 1; i <= m; ++i) {
			int fu = find(e[i].u);
			int fv = find(e[i].v);
			if (fu != fv) {
				f[fu] = fv;
				sum += e[i].w;
				path[++cnt] = i;
			}
		}
		for (int i = 1; i <= cnt; ++i) {
			int tot = 0, k = 0;
			for (int j = 1; j <= n; ++j)	f[j] = j;
			for (int j = 1; j <= m; ++j) {
				if (path[i] == j)	continue;
				int fu = find(e[j].u);
				int fv = find(e[j].v);
				if (fu != fv) {
					f[fu] = fv;
					tot += e[j].w;
					++k;
				}
			}
			if (k == n - 1 && tot == sum) {
				fl = 0;
				break;
			}
		}
		if (!fl)	puts("Not Unique!");
		else printf("%d\n", sum);
	}
	return 0;
}
