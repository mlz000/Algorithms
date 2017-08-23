#include <bits/stdc++.h>
using namespace std;
const int N = 20, inf = (int)1e9;
char s[N + 1][N + 1]; 
int cost[N][N], a[N][N], mask[N][N], dp[1 << N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)	scanf("%s", s[i]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			int mx = 0;
			for (int k = 0; k < n; ++k)	{
				if (s[i][j] == s[k][j]) {
					mask[i][j] |= 1 << k;
					cost[i][j] += a[k][j];
					mx = max(mx, a[k][j]);
				}
			}
			cost[i][j] -= mx;
		}
	int S = 1 << n;
	fill(dp, dp + S, inf);
	dp[0] = 0;
	for (int i = 1; i < S; ++i) {
		int lowbit = 0;
		while (!(i >> lowbit & 1))	++lowbit;
		for (int j = 0; j < m; ++j) {
			dp[i] = min(dp[i], dp[i ^ (1 << lowbit)] + a[lowbit][j]);
			dp[i] = min(dp[i], dp[i & (i ^ mask[lowbit][j])] + cost[lowbit][j]);
		}
	}
	printf("%d\n", dp[S - 1]);
	return 0;
}
