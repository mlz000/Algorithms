#include <bits/stdc++.h>
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	printf("%d\n",(6 * n - 1) * k);
	int now = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 3; ++j) {
			printf("%d ", now * k);
			++now;
		}
		++now;
		printf("%d\n", now * k);
		now += 2;
	}
	return 0;
}

