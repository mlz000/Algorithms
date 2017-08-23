#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
typedef long long LL;
struct data {
	int x, w;
}a[N];
bool cmp(const data &p, const data &q) {
	return p.x < q.x;
}
int n;
LL g[N];
int gao(int l, int r, LL x) {
	int t = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (x >= g[mid])	l = mid + 1;
		else r = mid - 1;
	}
	return l;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)	scanf("%d%d", &a[i].x, &a[i].w);
	sort(a + 1, a + n + 1, cmp);
	int now = 0;
	for (int i = 1; i <= n; ++i) {
		if (i == 1)	{
			g[++now] = a[i].x + a[i].w;
			continue;
		}
		if (a[i].x - a[i].w >= g[now])	g[++now] = a[i].x + a[i].w;
		else {
			int p = gao(1, now, a[i].x + a[i].w);
			g[p] = a[i].x + a[i].w;
		}
	}
	printf("%d\n", now);
	return 0;
}
