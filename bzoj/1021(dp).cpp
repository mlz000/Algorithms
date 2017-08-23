#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 10, M = 1001, inf = ~0u >> 1;
int x, y, z, sy, sx, sz, lx, ly, lz, now, a[N], b[N], c[N];
int cost[] = {1, 5, 10, 20, 50, 100};
int f[2][M][M];
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
inline void gao(int &x, int y) {
	if (x > y)	x = y;
}
int main() {
	read(x), read(y), read(z);
	for (int i = 5; i >= 0; --i)	read(a[i]), sx += a[i] * cost[i];
	for (int i = 5; i >= 0; --i)	read(b[i]), sy += b[i] * cost[i];
	for (int i = 5; i >= 0; --i)	read(c[i]), sz += c[i] * cost[i];
	lx = sx - x + z, ly = sy - y + x, lz = sz - z + y;
	int sum = sx + sy + sz;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < M; ++j)
			f[now][i][j] = inf;
	f[now][sx][sy] = 0;
	if ((lx < 0 + ly < 0 + lz < 0) != 0)	puts("impossible");
	else {
		for (int i = 0; i < 6; ++i, now ^= 1) {
			for (int j = 0; j < M; ++j)
				for (int k = 0; k < M; ++k)
					f[now ^ 1][j][k] = f[now][j][k];
			int t = cost[i];
			for (int j = i + 1; j < 6; ++j)	t = __gcd(t, cost[j]);
			int x = 0, y = 0;
			for (; (lx - x) % t; ++x);
			for (; (ly - y) % t; ++y);
			if ((lz - (sum - x - y)) % t)	continue;
			for (int j = x; j < M; j += t) {
				if (sum - j - y < 0)	break;
				for (int k = y; k < M; k += t) {
					int cc = sum - j - k;
					if (cc < 0)	break;
					if (f[now][j][k] == inf)	continue;
					//A->BC
					for (int l = 0; l <= a[i]; ++l) 
						if (j >= l * cost[i]) {
							for (int m = 0; m <= l; ++m)
								if (k + m * cost[i] < M && cc + (l - m) * cost[i] < M) gao(f[now ^ 1][j - l * cost[i]][k + m * cost[i]], f[now][j][k] + l);
						}
					//B->AC
					for (int l = 0; l <= b[i]; ++l) 
						if (k >= l * cost[i]) {
							for (int m = 0; m <= l; ++m)
								if (j + m * cost[i] < M && cc + (l - m) * cost[i] < M) gao(f[now ^ 1][j + m * cost[i]][k - l * cost[i]], f[now][j][k] + l);
						}
					//C->AB
					for (int l = 0; l <= c[i]; ++l)
						if (cc >= l * cost[i]) {
							for (int m = 0; m <= l; ++m)
								if (j + m * cost[i] < M && k + (l - m) * cost[i] < M) gao(f[now ^ 1][j + m * cost[i]][k + (l - m) * cost[i]], f[now][j][k] + l);
						}
					//AB->C
					for (int l = 0; l <= a[i]; ++l)
						if (j >= l * cost[i]) {
							for (int m = 0; m <= b[i]; ++m)
								if (k >= m * cost[i] && cc + (l + m) * cost[i] < M) gao(f[now ^ 1][j - l * cost[i]][k - m * cost[i]], f[now][j][k] + l + m);
						}
					//BC->A
					for (int l = 0; l <= b[i]; ++l)
						if (k >= l * cost[i]) {
							for (int m = 0; m <= c[i]; ++m)
								if (cc >= m * cost[i] && j + (l + m) * cost[i] < M)	gao(f[now ^ 1][j + (l + m) * cost[i]][k - l * cost[i]], f[now][j][k] + l + m);
						}
					//CA->B
					for (int l = 0; l <= c[i]; ++l)
						if (cc >= l * cost[i]) {
							for (int m = 0; m <= a[i]; ++m)
								if (j >= m * cost[i] && k + (l + m) * cost[i] < M)	gao(f[now ^ 1][j - m * cost[i]][k + (l + m) * cost[i]], f[now][j][k] + l + m);
						}
				}
			}
		}
		if (f[now][lx][ly] == inf)	puts("impossible");
		else printf("%d\n", f[now][lx][ly]);
	}
	return 0;
}
