#include <bits/stdc++.h>
using namespace std;
const int N = 300005, M = (int)1e9 + 9;
typedef long long LL;
LL a[N], d[N], sum[N], f[N], g[N];
int L[2005], R[2005];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%I64d", &a[i]);
		sum[i] = (sum[i - 1] + a[i]) % M;
	}
	f[1] = 1;
	g[1] = 1;
	for (int i = 2; i <= n; ++i) {
		f[i] = (f[i-1] + f[i-2]) % M;
		g[i] = (g[i-1] + f[i]) % M;
	}
	int k = 0;
	int block = sqrt(n);
	while (m--) {
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		if (op == 1) {
			L[++k] = l, R[k] = r;
			d[l] = (d[l] + 1) % M;
			d[r + 1] = (d[r + 1] - f[r - l + 2] + M) % M;
			d[r + 2] = (d[r + 2] - f[r - l + 1] + M) % M;
			if (k >= block) {
				for (int i = 1; i <= n; ++i) {
					if (i >= 2)	d[i] = (d[i] + d[i - 1] + d[i - 2]) % M;
					a[i] = (a[i] + d[i]) % M;
					sum[i] = (sum[i - 1] + a[i]) % M;
				}
				memset(d, 0, sizeof(d));
				k = 0;
			}
		}
		else {
			LL ans = 0;
			for (int i = 1; i <= k; ++i) {
				int le = max(l, L[i]);
				int ri = min(r, R[i]);
				if (le > ri)	continue;
				int st = le - L[i] + 1, ed = ri - L[i] + 1;
				ans = (ans + g[ed] - g[st - 1] + M) % M;
			}
			ans = (ans + sum[r] - sum[l - 1] + M) % M;
			printf("%I64d\n", ans);
		}
	}
	return 0;
}
