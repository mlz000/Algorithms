//DP
#include <cstdio>
#include <cstdlib>
#define N 15
#define M 100
typedef long long ll;
int m, n;
ll f[N + 1][M + 1];
int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; ++i) f[1][i] = 2 * i;
	for (int i = 1; i <= n; ++i) f[i][1] = 2;
	for (int i = 2; i <= n; ++i)
		for (int j = 2; j <= m; ++j)
			f[i][j] = f[i - 1][j - 1] + f[i][j - 1];
	printf("%lld\n", f[n][m]);
	return 0;
}
