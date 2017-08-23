#include <bits/stdc++.h>
using namespace std;
const int N = 18;
int a[N], mp[1 << 16];
int main() {
	int T, n, x;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt) {
		for (int i = 0; i < 16; ++i)	a[i] = -1;
		printf("Case #%d: ", tt);
		scanf("%d", &n);
		int all = (1 << 16) - 1, ans = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &x);
			mp[x] = tt;
			++ans;
			all &= x;
			for (int j = 0; j < 16; ++j) {
				if (x >> j & 1) {
					if (a[j] == -1)	a[j] = x;
					else a[j] &= x;
				}
			}
		}
		ans += (mp[all] != tt);
		mp[all] = tt;
		int tot = 0;
		for (int i = 0; i < 16; ++i)	if (~a[i])	a[tot++] = a[i];
		for (int i = 1; i < (1 << tot); ++i) {
			x = 0;
			for (int j = 0; j < tot; ++j)
				if (i >> j & 1)	x |= a[j];
			ans += (mp[x] != tt);
			mp[x] = tt;
		}
		printf("%d\n", ans - n);
	}
	return 0;
}

