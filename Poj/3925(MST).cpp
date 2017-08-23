//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
const int N = 25;
int n, m, tot, f[N], w[N], g[N][N];
struct data {
	int x, y, z;
	data(){}
	data(int x, int y, int z): x(x), y(y), z(z){}
}p[N * N];
bool cmp(const data &p, const data &q) {
	return p.z < q.z;
}
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
int gao() {
	for (int i = 0; i < n; ++i)	f[i] = i;
	sort(p, p + tot, cmp);
	int t = 0;
	for (int i = 0; i < tot; ++i) {
		int fx = find(p[i].x), fy = find(p[i].y);
		if (fx != fy) {
			f[fx] = fy;
			t += p[i].z;
		}
	}
	return t;
}
int main() {
	while (scanf("%d%d", &n, &m) && n || m) {
		for (int i = 0; i < n; ++i)	scanf("%d", &w[i]);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &g[i][j]);
		double ans = 1e18;
		int mask;
		for (int i = 1; i < 1 << n; ++i) {
			if (__builtin_popcount(i) != m)	continue;
			int y = 0;;
			tot = 0;
			for (int j = 0; j < n; ++j)
				if (i >> j & 1) {
					y += w[j];
					for (int k = 0; k < n; ++k)
						if (g[j][k] && (i >> k & 1)) p[tot++] = data(j, k, g[j][k]);
				}
			int x = gao();
			double t = (double)x / y;
			if (t < ans) {
				ans = t;	
				mask = i;
			}
		}
		for (int i = 0; i < n; ++i)
			if (mask >> i & 1)	printf("%d ", i + 1);
		puts("");
	}
	return 0;
}
