#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, k, a[N];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = n; i >= 1; i -= k)	ans += 2*(a[i] - 1);
	printf("%d", ans);
	return 0;
}
