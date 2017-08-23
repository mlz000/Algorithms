#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 16;
int a[N + 5];
LL f[N][N][1 << N][2];
LL dp(int pos, int mx, int s, bool eq) {
	LL &t = f[pos][mx][s][eq];
	if (!pos)	return t = (s >> mx) & 1;
	if (~t && !eq)	return t;
	t = 0;
	int r = eq ? a[pos] : 15;
	for (int i = 0; i <= r; ++i) {
		int mask = s;
		if (pos <= 4)	mask = s | (i << (pos - 1) * 4);
		t += dp(pos - 1, max(mx, i), mask, eq && i == r); 
	}
	return t;
}
LL gao(LL x) {
	if (x <= 0)	return 0;
	a[0] = 0;
	while (x) {
		a[++a[0]] = x & 15;
		x >>= 4;
	}
	return dp(a[0], 0, 0, 1);
}
int main() {
	int q;
	LL l, r;
	scanf("%d", &q);
	memset(f, -1, sizeof(f));
	while (q--) {
		scanf("%I64x%I64x", &l, &r);
		printf("%I64d\n", gao(r) - gao(l - 1));
	}
	return 0;
}

