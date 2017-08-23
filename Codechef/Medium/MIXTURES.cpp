#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const long long inf = 1ll << 31;
int a[N], sum[N];
long long dp[N][N];
int work(int l, int r) {
	return (sum[r] - sum[l - 1] + 100) % 100;
}
long long f(int l, int r) {
	if (l == r)	return dp[l][r] = 0;
	if (~dp[l][r])	return dp[l][r];
	dp[l][r] = inf;
	for (int k = l; k < r; ++k) {
		dp[l][r] = min(dp[l][r], f(l, k) + f(k + 1, r) + work(l, k) * work(k + 1, r)); 
	}
	return dp[l][r];
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		sum[0] = 0;
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			sum[i] = (sum[i - 1] + a[i]) % 100;
		}
		printf("%lld\n", f(1, n));
	}
	return 0;
}
