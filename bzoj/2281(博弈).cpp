#include <bits/stdc++.h>//nimk
using namespace std;
const int N = (int)1e4 + 5, M = (int)1e9 + 7;
typedef long long LL;
int f[16][N], c[N][205], p[15];
void add(int &x, int y) {
	x += y;
	if (x >= M)	x -= M;
}
int main() {
	int n, k, d;
	cin >> n >> k >> d;
	k >>= 1;
	for (int i = 0; i <= n; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= min(i, k << 1); ++j)	c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
	}
	p[0] = 1;
	for (int i = 1; i < 15; ++i)	p[i] = p[i - 1] << 1;
	f[0][0] = 1;
	for (int i = 0; i < 15; ++i)
		for (int j = 0; j <= n - 2 * k; ++j)
			for (int l = 0; l * (d + 1) <= k && j + l * (d + 1) * p[i] <= n - 2 * k; ++l)
				add(f[i + 1][j + l * (d + 1) * p[i]], (LL)f[i][j] * c[k][l * (d + 1)] % M);
	int ans = 0;
	for (int i = 0; i <= n - 2 * k; ++i)
		add(ans, (LL)f[15][i] * c[n - i - k][k] % M);
	int tot = c[n][k << 1];
	printf("%d\n", (tot - ans + M) % M);
	return 0;
}
