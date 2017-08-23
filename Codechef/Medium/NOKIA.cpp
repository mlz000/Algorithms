#include <bits/stdc++.h>
using namespace std;
const int N = 35;
int mx[N], mn[N];
int main() {
	int T, n, k;
	scanf("%d", &T);
	for (int i = 1; i <= 30; ++i) {
		mn[i] = 1e7;
		for (int j = 0; j < i; ++j) {
			mx[i] = max(mx[i], mx[j] + mx[i - j - 1] + i + 1);
			mn[i] = min(mn[i], mn[j] + mn[i - j - 1] + i + 1);
		}
	}
	while (T--) {
		scanf("%d%d", &n, &k);
		if (k < mn[n])	puts("-1");
		else if (mx[n] <= k)	printf("%d\n", k - mx[n]);
		else puts("0");
	}
	return 0;
}
