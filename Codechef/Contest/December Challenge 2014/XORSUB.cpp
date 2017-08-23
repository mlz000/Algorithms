#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, k, T, a[N], g[40][N];
void gauss() {
	long long ans = 0ll;
	int i, j;
	for (int r = 0; r <= 31; ++r) {
		if (k >> (31 - r) & 1)	g[r][n] = 0;
		else g[r][n] = 1;
		for (i = 0; i < r; ++i) {
			for (j = 0; j < n; ++j) {
				if (g[i][j])	break;
			}
			if (j < n && g[r][j]) {
				for (;  j <= n; ++j)	g[r][j] ^= g[i][j];
			}
		}
		for (i = 0; i < n; ++i) {
			if (g[r][i])	break;
		}
		if (i < n || (i == n && !g[r][n]))	ans |=  1 << (31 - r);
	}
	printf("%d\n", ans);
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			for (int j = 31; j >= 0; --j)	g[31 - j][i] = (a[i] >> j) & 1;
		}
		gauss();
	}
	return 0;
}
