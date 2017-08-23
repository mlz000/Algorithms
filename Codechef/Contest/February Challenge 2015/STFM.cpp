#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 10000005;
LL f[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	f[1] = 1 % m;
	for (int i = 2; i < m; ++i)	f[i] = f[i - 1] * i % m;
	LL ans = 0ll;
	for (int i = 1; i <= n; ++i) {
		long long x, t = 0ll;
		scanf("%lld", &x);
		if (x + 1 < m)	t = f[x + 1] % m;
		if (x & 1) {
			long long y = ((x + 1) / 2) % m;
			x = x % m;
			(t += x * x % m * y % m) %= m;
		}
		else {
			long long y = (x + 1) % m;
			long long z = (x / 2) % m;
			x = x % m;
			(t += x * y % m * z % m) %= m;
		}
		(t += m - 1) %= m;
		(ans += t) %= m;
	}
	printf("%lld\n", ans);
	return 0;
} 
