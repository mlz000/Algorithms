#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int mn = INT_MAX;
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			mn = min(mn, a[i]);
			sum += a[i];
		}
		if (mn < 2)	puts("-1");
		else printf("%d\n", sum - mn + 2);
	}
	return 0;
}
