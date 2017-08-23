#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int main() {
	int n, T;
	scanf("%d", &T);
	while (T--) {
		int t = 0;
		long long ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			if (a[i] > t)	ans += a[i] - t;
			t = a[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
