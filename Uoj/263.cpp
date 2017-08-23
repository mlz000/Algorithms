#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int c[N][N], g[N][N];
int main() {
	int t, k;
	scanf("%d%d", &t, &k);
	for (int i = 1; i <= 2000; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)	c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
	}
	c[0][0] = 1;
	for (int i = 1; i <= 2000; ++i)
		for (int j = 1; j <= i; ++j) {
			g[i][j] += g[i - 1][min(j, i - 1)] + g[i][j - 1] - g[i - 1][j - 1];
			if (c[i][j]  == 0)	++g[i][j];
		}
	while (t--) {
		int n, m;
		int cnt = 0;
		scanf("%d%d", &n, &m);
		printf("%d\n", g[n][min(n, m)]);
	}
	return 0;
}
