#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 55;
int a[N], dp[N][N * 1000];
int f(int x, int y) {
	if (dp[x][y] != -1)	return dp[x][y];
	if (y == 1)	return dp[x][y] = f(x + 1, 0);
	dp[x][y] = 0;
	if (x >= 1 && !f(x - 1, y))	dp[x][y] = 1;//取1
	if (y >= 2 && !f(x, y - 1))	dp[x][y] = 1;//取合并堆
	if (x >= 1 && y && !f(x - 1, y + 1))	dp[x][y] = 1;//1和堆合并
	if (x >= 2 && ((y && !f(x - 2, y + 3)) || (!y && !f(x - 2, 2))))	dp[x][y] = 1;//合并两个1
	return dp[x][y];
}
int main() {
	int T, n, m, k;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	for (int tt = 1; tt <= T; ++tt) {
		printf("Case #%d: ", tt);
		scanf("%d", &n);
		int x = 0, y = 0;//1的个数，其他堆合并
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			if (a[i] == 1)	++x;
			else y += a[i] + 1;
		}
		--y;
		int ans = f(x, y);
		printf("%s\n", ans ? "Alice" : "Bob");
	}
	return 0;
}
