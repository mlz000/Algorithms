#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], p[N], f[N << 1];
int find(int x) {	
	return f[x] == x ? x : f[x] = find(f[x]);
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
	for (int i = 1; i <= m; ++i)	f[i] = i, f[i + m] = i + m;
	for (int i = 1, x, y; i <= m; ++i) {
		scanf("%d", &x);
		while (x--) {
			scanf("%d", &y);
			if (!p[y])	p[y] = i;
			else {
				if (a[y]) {
					f[find(i)] = find(p[y]);
					f[find(i + m)] = find(p[y] + m);
				}
				else {
					f[find(i + m)] = find(p[y]);
					f[find(i)] = find(p[y] + m);
				}
			}
		}
	}
	for (int i = 1; i <= m; ++i)
		if (find(i) == find(i + m)) {
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}
