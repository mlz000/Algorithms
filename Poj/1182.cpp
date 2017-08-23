//#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 50005;
int f[N * 3];
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
void Union(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy)	f[fx] = fy;
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n * 3; ++i)	f[i] = i;
	int ans = 0;
	for (int i = 1; i <= k; ++i) {
		int d, x, y;
		bool p = 1;
		scanf("%d%d%d", &d, &x, &y);
		if (x > n || y > n) {
			++ans;
			continue;
		}
		if (d == 1) {
			if (find(x + n) == find(y))	p = 0;
			else if (find(x + 2 * n) == find(y))	p = 0;
			if (p) {
				Union(x, y), Union(x + n, y + n), Union(x + 2 * n, y + 2 * n);
			}
			else ++ans;
		}
		else {
			if (find(x) == find(y))	p = 0;
			else if (find(x + 2 * n) == find(y))	p = 0;
			if (p) {
				Union(x + n, y), Union(x + 2 * n, y + n), Union(x, y + 2 * n);
			}
			else ++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
