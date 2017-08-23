#include <bits/stdc++.h>
using namespace std;
int main() {
	int T, n, m;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		if (n < m)	puts("0");
		else {
			long long ans = 1ll;
			int x = n - 1, y = m - 1;
			y = min(y, x - y);
			for (int i = 1; i <= y; ++i) {
				ans *= x - i + 1;
				ans /= i;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}

