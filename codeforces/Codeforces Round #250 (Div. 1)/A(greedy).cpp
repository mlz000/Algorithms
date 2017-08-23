#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int a[N >> 1];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
	long long ans = 0ll;
	for (int i = 1, u, v; i <= m; ++i) {
		scanf("%d%d", &u, &v);
		if (a[u] < a[v])	ans += a[u];
		else ans += a[v];
	}
	printf("%I64d\n", ans);
	return 0;
}
