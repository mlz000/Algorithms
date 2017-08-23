#include <bits/stdc++.h>//dp+差分
using namespace std;
const int N = 205, M = 40002, P = 1e9 + 7;
int a[N], b[M * 2 + 10], dp[2][M * 2 + 10];
void gao1(int st, int num, int add) {
	(b[st] += add) %= P;
	(b[st + num * 2] += P - (add * 2 % P)) %= P;
	(b[st + num * 4] += add) %= P;
}
void gao2(int st, int num, int add) {
	(b[st] += add) %= P;
	(b[st + num * 2] += P - add) %= P;
	(b[st + (num + 1) * 2] += P - add) %= P;
	(b[st + (num * 2 + 1) * 2] += add) %= P;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
		int cur = 0;
		memset(dp, 0, sizeof(dp));
		dp[0][M] = 1;
		int tot = 0;
		for (int i = 1; i <= n; ++i) {
			if (!a[i])	continue;
			cur ^= 1;
			tot += a[i];
			for (int j = M - 2 - tot; j <= M + 2 + tot; ++j)	dp[cur][j] = b[j] = 0;	
			int odd = a[i] / 2 + 1, even = (a[i] + 1) / 2; 
			for (int j = M - 2 - tot; j <= M + 2 + tot; ++j) 
				if (dp[cur ^ 1][j]) {
					gao1(j - odd * 2, odd, dp[cur ^ 1][j]);//二次差分
					gao2(j - 1 - even * 2, even, dp[cur ^ 1][j]);
				}
			int last = 0, sum = 0;
			for (int j = M - 2 - tot; j <= M + 2 + tot; j += 2) {
				(last += sum) %= P;
				dp[cur][j] = last;
				(sum += b[j]) %= P;
			}
			last = sum = 0;
			for (int j = M - 2 - tot + 1; j <= M + 2 + tot; j += 2) {
				(last += sum) %= P;
				dp[cur][j] = last;
				(sum += b[j]) %= P;
			}
		}
		printf("%d\n", dp[cur][M]);
	}
	return 0;
}
