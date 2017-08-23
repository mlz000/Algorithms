#include <bits/stdc++.h>
using namespace std;
const int N = 105, M = (int)1e9 + 7;
typedef long long LL;
LL a[N];
int dp[N][N];
int dfs(int l, int r) {
	if (dp[l][r])	return dp[l][r];
	int &t = dp[l][r];
	if (l >= r)	return t = 1;
	if (a[l] > 0)	return t = dfs(l + 1, r);
	t = dfs(l + 1, r);
	for (int i = l + 1; i <= r; ++i) {
		if ((a[i] > 0) && (a[l] + a[i] == 0)) {
			(t += ((LL)dfs(l + 1, i - 1) * dfs(i + 1, r) % M)) %= M;
		}
	}
	return t;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)	scanf("%lld", &a[i]);
	printf("%d\n", dfs(0, n - 1));
	return 0;
}
