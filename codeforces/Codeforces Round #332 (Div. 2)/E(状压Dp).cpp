#include <bits/stdc++.h>
const int N = 13, M = 105;
typedef long long LL;
int u[N], v[N], a[M], b[M], c[M], needrt[1 << N], rt[1 << N];
LL dp[1 << N][N], g[1 << N];
bool ok[1 << N];
int n, m, q;
LL gao(int mask, int root);
LL gao2(int mask) {
	LL &t = g[mask];
	if (~t)	return t;
	t = 0;
	if (~rt[mask])	t = gao(mask ^ (1 << rt[mask]), rt[mask]);
	else {
		for (int i = 0; i < n; ++i)
			if (mask >> i & 1)	t += gao(mask ^ (1 << i), i);
	}
	return t;
}
LL gao(int mask, int root) {
	LL &t = dp[mask][root];
	if (~t)	return t;
	if (!mask)	return t = 1;
	t = 0;
	int x = mask & -mask;
	for (int i = mask; i; i = (i - 1) & mask) {
		if (~i & x || !ok[i] || (~needrt[i] && needrt[i] != root))	continue;
		t += gao(mask ^ i, root) * gao2(i);
	}
	return t;
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &u[i], &v[i]);
		--u[i], --v[i];
	}
	for (int i = 0; i < q; ++i) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		--a[i], --b[i], --c[i];
	}
	for (int i = 0; i < 1 << n; ++i) {
		ok[i] = 1;
		g[i] = needrt[i] = rt[i] = -1;
		for (int j = 0; j < n; ++j)	dp[i][j] = -1;
		for (int j = 0; j < m; ++j) {
			int t = -1;
			if ((i >> u[j] & 1) && (~i >> v[j] & 1))	t = v[j];
			if ((i >> v[j] & 1) && (~i >> u[j] & 1))	t = u[j];
			if (~t) {
				if (needrt[i] == -1)	needrt[i] = t, rt[i] = u[j] + v[j] - t;
				else {
					ok[i] = 0;
					break;
				}
			}
		}
		for (int j = 0; j < q; ++j) {
			int cnt = 0;
			bool f = 0;
			if (i >> a[j] & 1)	++cnt;
			if (i >> b[j] & 1)	++cnt;
			if (i >> c[j] & 1)	++cnt, f = 1;
			if (cnt == 2 || (cnt == 1 && f)) {
				ok[i] = 0;
				break;
			}
		}
	}
	printf("%I64d\n", gao((1 << n) - 2, 0));
	return 0;
}
