#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = (int)1e9 + 7;
int a[N];
long long f[N][N];
int main() {
	int T, n, k;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
		sort(a + 1, a + n + 1, greater<int>());
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			int j = i;
			while(j <= n && a[j] == a[i])	++j;
			a[++cnt] = j - i;
			i = j - 1;
		}
		memset(f, 0, sizeof(f));
		f[0][0] = 1ll;
		int sum = 0;
		for (int i = 1; i <= cnt; ++i) {
			long long x = 1ll, y = 1ll;
			for (int j = sum; j < sum + a[i]; ++j)	x = x * (j + 1) % M, y = y * j % M;
			x = (x - y + M) % M;
			for (int j = 0; j <= k; ++j) {
				f[i][j + 1] = (f[i][j + 1] + f[i - 1][j] * x % M) % M;
				f[i][j] = (f[i][j] + f[i - 1][j] * y % M) % M;
			}
			sum += a[i];
		}
		int ans = 0;
		for (int i = 0; i <= k; ++i)	(ans += f[cnt][i]) %= M;
		printf("%d\n", ans);
	}
	return 0;
}
