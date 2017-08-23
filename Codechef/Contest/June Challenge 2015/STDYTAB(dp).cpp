#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2005, M = 1e9;
int c[N << 1][N], dp[N][N], sum[N];
int main() {
	int n, m, T;
	for (int i = 0; i <= 4000; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= min(2000, i); ++j)	c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		fill(sum, sum + m + 1, 1);
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= m; ++j)
				dp[i][j] = (LL)sum[j] * c[m + j - 1][j] % M;
			sum[0] = dp[i][0];
			for (int j = 1; j <= m; ++j)	sum[j] = (sum[j - 1] + dp[i][j]) % M;
		}
		printf("%d\n", sum[m]);
	}
	return 0;
}
