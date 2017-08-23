#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int dp[N][N], pre[N], cnt[N];
char a[N], b[N];
int main() {
	scanf("%s%s", a, b);
	int n = strlen(a), m = strlen(b);
	memset(pre, -1, sizeof(pre));
	for (int i = 0; i < n; ++i) {
		int k = i;
		int j = 0;
		while(k < n && j < m) {
			if (a[k] == b[j])	++j;
			++k;
		}	
		if (j == m)	pre[k] = i, cnt[k] = k - i - m;
	}
	for (int i = 1; i <= n; ++i) 
		for (int j = 0; j < i; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (j)	dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
			if (pre[i] != -1 && cnt[i] <= j) {
				if (pre[i] >= j - cnt[i])	dp[i][j] = max(dp[i][j], dp[pre[i]][j - cnt[i]] + 1);
			}
		}
	for (int i = 0; i <= n; ++i)	printf("%d ", dp[n][i]);
	return 0;
}
