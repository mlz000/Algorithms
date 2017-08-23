#include <bits/stdc++.h>
const int N = 1005;
int a[N], b[N];
int main() {
	freopen("knockout.in", "r", stdin);
	freopen("knockout.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)	scanf("%d%d", &a[i], &b[i]);
	for (int i = 1; i <= m; ++i) {
		 int x, y, t;
		 scanf("%d%d%d", &x, &y, &t);
		 int ans = 0, pos;
		 for (int j = 1; j <= n; ++j) {
			if (a[j] == b[j])	pos = a[j];
			else if (a[j] > b[j]) {
				int d = a[j] - b[j];
				int cnt = t % (2 * d);
				if (cnt >= d) {
					pos = b[j] + cnt % d;
				}
				else pos = a[j] - cnt;
			}
			else {
				int d = b[j] - a[j];
				int cnt = t % (2 * d);
				if (cnt >= d) {
					pos = b[j] - cnt % d;
				}
				else pos = a[j] + cnt;
			}
			if (pos >= x && pos <= y)	++ans;
		 }
		 printf("%d\n", ans);
	}
	return 0;
}
	
