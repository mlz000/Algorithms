#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N = 10005;
int n, m, f[N];
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
struct data {
	int u, v, w;
}e[N];
bool cmp(const data &p, const data &q) {
	return p.w < q.w;
}
int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 1; i <= n; ++i)	f[i] = i;
		for (int i = 1; i <= m; ++i)	scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
		sort(&e[1], &e[m + 1], cmp);
		int ans = 0;
		for (int i = 1; i <= m; ++i) {
			int fu = find(e[i].u);
			int fv = find(e[i].v);
			if (fu != fv) {
				f[fu] = fv;
				ans = max(ans, e[i].w);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
