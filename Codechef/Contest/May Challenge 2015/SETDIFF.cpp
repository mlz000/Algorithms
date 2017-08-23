#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 5, M = 1e9 + 7;
LL a[N], sum[N], p[N];
int main() {
	int T, n;
	scanf("%d", &T);
	p[0] = 1;
	for (int i = 1; i <= 1e5; ++i)	p[i] = p[i - 1] * 2 % M; 
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)	scanf("%lld", &a[i]);
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; ++i)	sum[i] = sum[i - 1] + a[i];
		LL ans = 0;
		for (int i = 1; i <= n; ++i) {
			(ans += a[i] * p[i - 1] % M) %= M;
			(ans -= a[i] * p[n - i] % M - M) %= M; 
		}
		printf("%lld\n", ans);
	}
	return 0;
}
