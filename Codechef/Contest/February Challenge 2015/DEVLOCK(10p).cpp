#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 998244353;
long long dp[N][55][55];
int main() {
	int n, mm, p;
	scanf("%d%d%d", &n, &p, &mm);
	if (n > 1000) return 0;	
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < p; ++j)
			for (int k = 0; k <= mm; ++k)
				for (int l = 0; l <= 9; ++l)
					if (dp[i - 1][j][k] && k + l <= mm)	
						(dp[i][(10 * j + l) % p][k + l] += dp[i - 1][j][k]) %= M;
	for (int i = 1; i <= mm; ++i)	(dp[n][0][i] += dp[n][0][i - 1]) %= M;
	for (int i = 0; i <= mm; ++i)	printf("%lld ", dp[n][0][i]);
	return 0;
}
