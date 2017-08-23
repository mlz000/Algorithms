#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
char A[N], B[N][N];
int c[10], g[N], b[N][N], l[N], f[N][N], sa[N][N], ss[N];
int gao(int x, int y) {
	if (y > max(l[x], l[0]) && !g[x])	return 0;
	return c[g[x]];
}
int main() {
	scanf("%s", A + 1);
	l[0] = strlen(A + 1);
	reverse(A + 1, A + l[0] + 1);
	int n, m = l[0];
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", B[i] + 1);
		l[i] = strlen(B[i] + 1);
		m = max(m, l[i]);
		reverse(B[i] + 1, B[i] + l[i] + 1);
	}
	for (int i = 0; i < 10; ++i)	scanf("%d", &c[i]);
	++m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (j <= l[i])	b[i][j] = B[i][j] - '0';
			else b[i][j] = 0;
		}
	memset(f, -63, sizeof(f));
	f[0][0] = 0;
	for (int i = 1; i <= n; ++i)	sa[0][i] = i;
	for (int j = 1; j <= m; ++j) {
		memset(ss, 0, sizeof(ss));
		for (int i = 1; i <= n; ++i)	++ss[b[i][j]];
		for (int i = 9; i >= 1; --i)	ss[i - 1] += ss[i];
		for (int i = n; i >= 1; --i)	sa[j][ss[b[sa[j - 1][i]][j]]--] = sa[j - 1][i];
		int L = 0, R = 0;
		if (j > l[0])	L = R = 0;
		else if (A[j] == '?')	L = (j == l[0]), R = 9;
		else L = R = A[j] - '0';
		for (int i = L, cnt, v; i <= R; ++i) {
			cnt = v = 0;
			for (int k = 1; k <= n; ++k) {
				g[k] = b[k][j] + i;
				if (g[k] > 9)	g[k] -= 10, ++cnt;
				v += gao(k, j);
			}
			for (int k = 0; ;) {
				f[j][cnt] = max(f[j][cnt], f[j - 1][k] + v);
				if (k++ == n)	break;
				v -= gao(sa[j - 1][k], j);
				if ((++g[sa[j - 1][k]]) > 9)	g[sa[j - 1][k]] -= 10, ++cnt;
				v += gao(sa[j - 1][k], j);
			}
		}
	}
	printf("%d\n", f[m][0]);
	return 0;
}
