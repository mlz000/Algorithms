#include <bits/stdc++.h>
using namespace std;
const int N = 19;
const double eps = 1e-10;
double x[N], y[N];
int tot, n, m, mask[N * N], dp[1 << N];
void gao(int i, int j) {
	if (i == j)	{
		mask[tot++] = 1 << i;
		return;
	}
	double a = (y[i] * x[j] - y[j] * x[i]) / (x[i] * x[j] * (x[i] - x[j]));
	double b = (y[i] - a * x[i] * x[i]) / x[i];
	if (a >= 0 || abs(a) < eps)	return;
	for (int i = 0; i < n; ++i)
		if (fabs(a * x[i] * x[i] + b * x[i] - y[i]) < eps) mask[tot] |= 1 << i;
	tot++;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		tot = 0;
		memset(mask, 0, sizeof(mask));
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)	scanf("%lf%lf", &x[i], &y[i]);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j <= i; ++j)
				gao(i, j);
		for (int i = 1; i < 1 << n; ++i)	dp[i] = 1000000;
		dp[0] = 0;
		for (int i = 0; i < tot; ++i)
			for (int j = 0; j < 1 << n; ++j)
				if (dp[j | mask[i]] > dp[j] + 1) {
					dp[j | mask[i]] = dp[j] + 1;
				}
		printf("%d\n", dp[(1 << n) - 1]);
	}
	return 0;
} 
