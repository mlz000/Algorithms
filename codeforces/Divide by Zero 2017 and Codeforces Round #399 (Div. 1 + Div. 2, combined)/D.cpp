#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int ans[N], p[N];
double dp[N * 10][N];
int main() {
	int k, q;
	scanf("%d%d", &k, &q);
	for (int i = 1; i <= q; ++i)	scanf("%d", &p[i]);
	dp[0][0] = 1.0;
	for (int i = 1; ; ++i) {
		dp[i][0] = 0;
		for (int j = 1; j <= k; ++j) {
			dp[i][j] = dp[i - 1][j - 1] * (k - j + 1) / k + dp[i - 1][j] * j / k;
		}
		if (dp[i][k] * 2 >= 1)	break;
	}
	int now = 1;
	for (int i = 1; i <= 1000; ++i) {
		while (dp[now][k] * 2000 < i)	++now;
		ans[i] = now;
	}
	for (int i = 1; i <= q; ++i)	printf("%d\n", ans[p[i]]);
	return 0;
}

