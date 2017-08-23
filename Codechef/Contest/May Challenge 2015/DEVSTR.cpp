#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 5;
char s[N];
int a[N], p[N], l[N], r[N], f[N][2];
int main() {
	int n, k, T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		scanf("%s", s + 1);
		for (int i = 1; i <= n; ++i)	a[i] = s[i] - '0';
		if (k == 1) {
			int cnt1 = 0, cnt2 = 0;
			for (int i = 1; i <= n; ++i) {
				if (i & 1)	cnt1 += !a[i];		
				else cnt1 += a[i];
			}
			for (int i = 1; i <= n; ++i) {
				if (i % 2 == 0)	cnt2 += !a[i];
				else cnt2 += a[i];
			}
			printf("%d\n", min(cnt1, cnt2));
			if (cnt1 < cnt2) {
				for (int i = 1; i <= n; ++i)	printf("%d", i & 1);
			}
			else for (int i = 1; i <= n; ++i)	printf("%d", !(i & 1));
			puts("");
			continue;
		}
		int ans = 0;
		a[0] = a[n + 1] = 2;
		int now = 0;
		for (int i = 1; i <= n + 1; ++i) {
			if (a[i] == a[i - 1]) continue;
			else {
				r[now] = i - 1;
				++now;
				l[now] = i;
			}
		}
		--now;
		for (int i = 1; i <= now; ++i) {
			int sz = r[i] - l[i] + 1;
			if (sz <= k)	continue;
			else {
				for (int j = l[i] + k; j <= r[i]; j += k + 1) a[j] ^= 1, ++ans;
				if (a[r[i]] == a[l[i + 1]]) {
					for (int j = l[i] + k; j <= r[i]; j += k + 1) a[j] ^= 1, --ans;
					for (int j = l[i] + k - 1; j <= r[i]; j += k + 1)	a[j] ^= 1, ++ans;
				}
			}
		}
		printf("%d\n", ans);
		for (int i = 1; i <= n; ++i)	printf("%d", a[i]);
		puts("");
	}
	return 0;
}
