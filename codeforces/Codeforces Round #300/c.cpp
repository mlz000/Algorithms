#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int d[N], h[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &d[i], &h[i]);
		if (i == 1) {
			ans = h[1] + d[1] - 1;
			continue;
		}
		int l = h[i - 1] - d[i] + d[i - 1];
		int r = h[i - 1] + d[i] - d[i - 1];
		if ((h[i] < l) || (h[i] > r)) {
			puts("IMPOSSIBLE"); 
			return 0; 
		}
		ans = max(ans, (h[i - 1] + h[i] + d[i] - d[i - 1]) / 2);
	}
	if (d[m] < n) ans = max(ans, h[m] - d[m] + n);
	printf("%d\n", ans);
	return 0;
}
