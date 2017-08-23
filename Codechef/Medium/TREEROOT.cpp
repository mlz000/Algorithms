#include <bits/stdc++.h>
using namespace std;
int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int sum1 = 0, sum2 = 0;
		for (int i = 1, x, y; i <= n; ++i) {
			scanf("%d%d", &x, &y);
			sum1 += x, sum2 += y;
		}
		printf("%d\n", sum1 - sum2);
	}
	return 0;
}
