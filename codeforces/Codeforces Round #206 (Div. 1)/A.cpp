#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int w[N];
int main() {
	int n, l, r, ql, qr, ans = ~0u >> 1;
	scanf("%d%d%d%d%d", &n, &l, &r, &ql, &qr);
	for (int i = 1; i <= n; ++i)	scanf("%d", &w[i]), w[i] += w[i - 1];
	for (int i = 0; i <= n; ++i) {
		int t = w[i] * l + (w[n] - w[i])* r;
		if (i * 2 - n > 1)	t += ql * (i * 2 - n - 1);
		else if (n - i * 2 > 1)	t += qr * (n - 2 * i - 1);
		ans = min(ans, t);
	}
	printf("%d\n", ans);
	return 0;
}
