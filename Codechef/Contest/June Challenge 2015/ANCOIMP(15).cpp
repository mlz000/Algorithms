#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1005;
int n, T, a[N][N], b[N][N], y[N], yy[N][N], g[N], ans[N];
void bf() {
	int mx = 0;
	bool can = 0;
	for (int i = 0; i < 1 << (n - 1); ++i) {
		for (int j = 0; j < n; ++j)	y[n - j] = i >> j & 1;
		y[1] = 0;
		int cnt = 0;
		bool ok = 1;
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k) {
				yy[j][k] = y[j] ^ y[k];
				if (yy[j][k])	++cnt;
				if (~b[j][k] && b[j][k] != yy[j][k]) {
					ok = 0;
					break;
				}
			}
		if (ok) {
			can = 1;
			if (cnt > mx) {
				mx = cnt;
				for (int j = 1; j <= n; ++j)	ans[j] = y[j];
			}
		}
	}
	if (!can)	puts("-1");
	else {
		for (int j = 1; j <= n; ++j)	printf("%d ", ans[j]);
		puts("");
	}
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			g[i] = -1;
			for (int j = 1; j <= n; ++j)
				b[i][j] = -1;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				scanf("%d", &a[i][j]);
				if (a[i][j])	b[i][j] = a[i][j];
			}
		}
		bool ok = 1;
		for (int j = 1; j <= n; ++j)
			if (b[j][j] == 1) {
				ok = 0;
				break;
			}
		for (int j = 1; j <= n; ++j)	b[j][j] = 0;
		int cnt = 0;
		for (int j = 1; j <= n; ++j) {
			if (b[1][j] == 1) {
				for (int k = 1; k <= n; ++k) {
					if (b[1][k] == 1)	{
						if (b[j][k] == 1) {
							ok = 0;
							break;
						}
						else b[j][k] = 0;
					}
					if (b[j][k] == 1) {
						if (b[1][k] == 1) {
							ok = 0;
							break;
						}
						else b[1][k] = 0;
					}
				}
			}
		}
		for (int j = 1; j <= n; ++j)
			if (b[1][j] == 1)	++cnt;
		if (!ok)	{puts("-1");continue;}
		for (int j = 1; j <= n; ++j)
			for (int i = 1; i <= n; ++i) {
				if (~b[i][j] && ~b[1][j]) {
					if (b[i][j] != b[1][j])	g[i] = 0;//diff
					else g[i] = 1;//same
				}
			}
		if (n <= 10) {//bf
			bf();
			continue;
		}
		for (int j = 1; j <= n; ++j) {
			if (b[1][j] == -1) {
				bool ok1 = 1, ok2 = 1;
				for (int i = 1; i <= n; ++i) {
					if (!g[i] && b[i][j] == 1) {
						ok1 = 0;
						break;
					}
					if (g[i] == 1 && b[i][j] == 0) {
						ok1 = 0;
						break;
					}
				}
				for (int i = 1; i <= n; ++i) {
					if (!g[i] && b[i][j] == 0) {
						ok2 = 0;
						break;
					}
					if (g[i] && b[i][j] == 1) {
						ok2 = 0;
						break;
					}
				}	
				if (!ok1 && !ok2) {
					ok = 0;
					break;
				}
				else if (ok1 && (cnt < n / 2 || !ok2))	b[1][j] = 1, ++cnt;
				else if (ok2)	b[1][j] = 0;
			}
		}
		if (!ok)	{puts("-1");continue;}
		for (int j = 1; j <= n; ++j)	printf("%d ", b[1][j]);
		puts("");
	}
	return 0;
}
