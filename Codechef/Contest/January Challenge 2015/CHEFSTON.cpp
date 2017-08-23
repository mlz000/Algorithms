#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N], b[N];
int main() {
	int n, T, k;
	scanf("%d", &T);
	while (T--) {
		long long ans = 0ll;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &b[i]);
			ans = max(ans, (long long) k / a[i] * b[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

