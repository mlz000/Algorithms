#include <bits/stdc++.h>//Dp单调性优化 
using namespace std;
const int N=10005;
int c[N], f[205][105];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)	scanf("%d", &c[i]);
	for (int i = 0; i < 101; ++i)	f[0][i] = 0;
	for (int i = 1; i <= n + 1; ++i) {
		for (int j = 0; j < 101; ++j)	f[i % 105][j] = INT_MAX;
		for (int j = 1; i - j >= 0 && j <= m; ++j) {
			int k = (i > m) ? m - j : i - j;
			if (f[(i - j) % 105][k] < INT_MAX)	f[i % 105][j] = f[(i - j) % 105][k] + c[i];
			if (f[i % 105][j] > f[i % 105][j - 1])	f[i % 105][j] = f[i % 105][j - 1];
		}
	}
	cout << f[(n + 1) % 105][m] << endl;
	return 0;
}
