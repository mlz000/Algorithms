#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 205, P = 1e9 + 7;
int n, m, K;
char a[N], b[M];
int f[2][N][M], s[2][N][M];
int main() {
	scanf("%d%d%d", &n, &m, &K);
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	s[0][0][0] = s[1][0][0] = 1;
	for (int i = 1; i <= n + 1; ++i) {
		for (int j = 1; j <= m; ++j)
			for (int k = 1; k <= K; ++k) {
				s[i & 1][j][k] = (s[~i & 1][j][k] + f[~i & 1][j][k]) % P; 
				if (a[i] == b[j]) {
					f[i & 1][j][k] = (f[~i & 1][j - 1][k] + s[i & 1][j - 1][k - 1]) % P;
				}
				else f[i & 1][j][k] = 0;
			}
	}
	printf("%d\n", s[~n & 1][m][K]);
	return 0;
}
