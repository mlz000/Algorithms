#include <bits/stdc++.h>//ÈÝ³â2´Î
using namespace std;
typedef long long LL;
const int N = 1005, M = (int)1e9 + 7;
int n, m, tot, f[N], g[N];
int P(int x, int y) {
	int t = 1;
	if (y == 0)	return t;
	for (; y; y >>= 1) {
		if (y & 1)	t = (LL)t * x % M;
		x = (LL)x * x % M;
	}
	return t;
}
int gao2(int num2) {
	int t = 0;
	for (int i = 0; i < 1 << num2; ++i) {
		int mul = 1;
		for (int j = 0; j < num2; ++j)
			if (i >> j & 1)	mul *= g[j];
		int now = m - m / mul;
		if (__builtin_popcount(i) & 1)	(t += now) %= M;
		else (t = t - now + M) % M;
	}
	return t;
}
int gao(int x) {
	int t = 0, num = 0;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i)	continue;
		int now = 1;
		while (x % i == 0) x /= i, now *= i;	
		f[num++] = now;
	}
	if (x > 1)	f[num++] = x;
	for (int i = 0; i < 1 << num; ++i) {
		int num2 = 0;
		for (int j = 0; j < num; ++j)
			if (i >> j & 1)	g[num2++] = f[j];
		int now = gao2(num2);
		now = P(now, n);
		if (__builtin_popcount(i) & 1)	(t += now) %= M;
		else (t = t - now + M) %= M;
	}
	return (tot - t + M) % M;
}
int main() {
	int T, l, r;
	scanf("%d", &T);
	while (T--) {
		int ans = 0;
		scanf("%d%d%d%d", &n, &m, &l, &r);
		tot = P(m, n);
		for (int i = l; i <= r; ++i)	(ans += gao(i)) %= M;
		printf("%d\n", ans);
	}
	return 0;
}
