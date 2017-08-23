#include <bits/stdc++.h>
using namespace std;
const int N = 16, M = (int)1e9 + 7;
int sum[N], lcs[N], a[1 << 15][N], dp[2][1 << 15];
char s[N + 1];
char t[] = {'A', 'G', 'C', 'T'};
inline void add(int &x, int y) {
	x += y;
	if (x >= M)	x -= M;
}
int ans[N];
int main() {
	int T, m;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s + 1);
		scanf("%d", &m);
		int l = strlen(s + 1);
		for (int i = 0; i < 1 << l; ++i) {
			sum[0] = 0;
			for (int j = 1; j <= l; ++j)	sum[j] = sum[j - 1] + (i >> (j - 1) & 1);
			for (int k = 0; k < 4; ++k) {
				for (int j = 1; j <= l; ++j) {
					if (s[j] == t[k])	lcs[j] = sum[j - 1] + 1;
					else lcs[j] = max(lcs[j - 1], sum[j]);
				}
				int &tmp = a[i][k] = 0;//state i + t[k] 
				for (int j = 1; j <= l; ++j)	tmp |= (lcs[j] != lcs[j - 1]) << (j - 1);
			}
		}
		int now = 0;
		memset(dp[0], 0, sizeof(dp[0]));
		dp[0][0] = 1;
		for (int i = 1; i <= m; ++i) {
			memset(dp[now ^ 1], 0, sizeof(dp[now ^ 1]));
			for (int j = 0; j < 1 << l; ++j)
				for (int k = 0; k < 4; ++k)
					add(dp[now ^ 1][a[j][k]], dp[now][j]);
			now ^= 1;
		}
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < 1 << l; ++i)
			add(ans[__builtin_popcount(i)], dp[now][i]);
		for (int i = 0; i <= l; ++i)	printf("%d\n", ans[i]);
	}
	return 0;
}
