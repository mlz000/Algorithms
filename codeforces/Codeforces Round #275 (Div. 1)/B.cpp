#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], l[N], r[N], q[N], d[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)	scanf("%d%d%d", &l[i], &r[i], &q[i]);
	bool f = 1;
	for (int i = 0; i < 30; ++i) {
		memset(d, 0, sizeof(d));
		for (int j = 1; j <= m; ++j)	if (q[j] >> i & 1)	++d[l[j]], --d[r[j] + 1];
		for (int j = 1; j <= n; ++j) {
			d[j] += d[j - 1];
			if (d[j])	a[j] |= 1 << i;
		}
		for (int j = 1; j <= n; ++j) {
			if (d[j])	d[j] = d[j - 1] + 1;
			else d[j] = d[j - 1];
		}
		for (int j = 1; j <= m; ++j) {
			if (q[j] >> i & 1) {
				if (d[r[j]] - d[l[j] - 1] != r[j] - l[j] + 1) {
					f = 0;
					break;
				}
			}
			else {
				if (d[r[j]] - d[l[j] - 1] == r[j] - l[j] + 1) {
					f = 0;
					break;
				}
			}
		}
		if (!f)	break;
	}
	if (!f)	puts("NO");
	else {
		puts("YES");
		for (int i = 1; i <= n; ++i)	printf("%d ", a[i]);
	}
	return 0;
}
