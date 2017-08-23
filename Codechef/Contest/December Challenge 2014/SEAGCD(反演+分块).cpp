#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = (int)1e7 + 5, M = (int)1e9 + 7;
int tot, mu[N], sum[N], g[N], p[(int)1e6];
LL po[N]; 
bool check[N];
int P(int x, int y) {
	int t = 1;
	if (y == 1)	return x;
	for (; y; y >>= 1) {
		if (y & 1) t = (LL)t * x % M;
		x = (LL)x * x % M;
	}
	return t;
}
void init() {
	mu[1] = 1;
	for (int i = 2; i <= (int)1e7; ++i) {
		if (!check[i])	p[++tot] = i, mu[i] = -1;
		for (int j = 1; j <= tot && i * p[j] <= (int)1e7; ++j) {
			check[i * p[j]] = 1;
			if (i % p[j])	mu[i * p[j]] = -mu[i];
			else {
				mu[i * p[j]] = 0;
				break;
			}
		}
	}
	for (int i = 1; i <= (int)1e7; ++i)	sum[i] = sum[i - 1] + mu[i];
}
void gao(int n, int m) {
	memset(po, 0, sizeof(po));
	po[1] = 1;
	for (int i = 2; i <= m; ++i) {
		if (!check[i])	po[i] = P(i, n);
		for (int j = 1; j <= tot && i * p[j] <= m; ++j) {
			po[i * p[j]] = po[i] * po[p[j]] % M;
			if (i % p[j] == 0)	break;
		}
	}
}
int main() {
	int n, m, l, r, T;
	init();
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d", &n, &m, &l, &r);
		gao(n, m);
		LL ans = 0ll, t;
		for (int i = l, last; i <= r; i = last + 1) {
			t = 0ll;
			last = min(r, m / (m / i));
			int x = m / last;
			for (int j = 1, last2; j <= x; j = last2 + 1) {
				last2 = x / (x / j);
				(t += ((po[x / j] * (sum[last2] - sum[j - 1]) % M) + M) % M) %= M;
			}
			(ans += t * (last - i + 1) % M) %= M;
		}
		printf("%d\n", ans);
	}
	return 0;
}
