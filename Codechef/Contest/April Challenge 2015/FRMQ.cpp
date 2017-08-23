#include <bits/stdc++.h>//70
using namespace std;
typedef long long LL;
const int N = 1e5 + 5;
int a[N], d[N][30];
int main() {
	int n, q, x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)	scanf("%d", &a[i]), d[i][0] = a[i];
	for (int j = 1; (1 << j) <= n; ++j)
		for (int i = 0; i + (1 << j) - 1 < n; ++i)
			d[i][j] = max(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
	scanf("%d%d%d", &q, &x, &y);
	long long ans = 0;
	while (q--) {
		int l = min(x, y), r = max(x, y);
		r = min(r, n - 1);
		int k = 0;
		while (1 << (k + 1) <= r - l + 1)	++k;
		ans += max(d[l][k], d[r - (1 << k) + 1][k]);
		x = (x + 7) % (n - 1);
		y = (y + 11) % n;
	}
	printf("%lld\n", ans);
	return 0;
}
