#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long LL;
const LL inf = 1e18;
int b[N];
LL c[N];
int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	LL sum = 0;
	for (int i = 1, x; i <= n; ++i) scanf("%d", &x), sum += ((i & 1) ? 1 : -1) * x;
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &b[i]);
		if (i <= n) c[0] += ((i & 1) ? -1 : 1) * b[i];
	}
	for (int i = 1; i <= m - n; ++i)	c[i] = -c[i - 1] + (((n & 1) ? -1 : 1) * b[n + i]) - b[i];
	c[m - n + 1] = -inf, c[m - n + 2] = inf;
	sort(c, c + m - n + 3);
	int p = lower_bound(c, c + m - n + 3, -sum) - c;
	printf("%I64d\n", min(abs(c[p] + sum), abs(c[p - 1] + sum)));
	while (q--) {
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		int num = r - l + 1;
		if (num & 1)	sum += ((l & 1) ? 1 : -1) * x;
		int p = lower_bound(c, c + m - n + 3, -sum) - c;
		printf("%I64d\n", min(abs(c[p] + sum), abs(c[p - 1] + sum)));
	}
	return 0;
}
