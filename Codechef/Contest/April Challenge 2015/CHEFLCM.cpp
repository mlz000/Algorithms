#include <bits/stdc++.h>
typedef long long LL;
const int N = 1e5;
int n, T;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		LL ans = 1;
		LL tn = n;
		for (int i = 2; i * i <= n; ++i) {
			if (n % i == 0) {
				LL t = i;
				while (n % i == 0 && n)	n /= i, t *= i;
				ans *= (t - 1) / (i - 1);
			}
		}
		if (n > 1)	ans *= (n + 1);
		printf("%lld\n", ans);
	}
	return 0;
}
