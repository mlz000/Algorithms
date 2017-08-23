#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 5, M = 20;
int a[N];
LL f[N][M], p[M];
int main() {
	int n, k, x;
	scanf("%d%d%d", &n, &k, &x);
	for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
	p[0] = 1;
	for (int i = 1; i <= k; ++i)	p[i] = p[i - 1] * x;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= k; ++j)
			for (int l = 0; l <= j; ++l)
				f[i][j] = max(f[i][j], f[i - 1][l] | (p[j - l] * a[i]));
	cout << f[n][k] << endl;
	return 0;
}
