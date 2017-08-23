#include <bits/stdc++.h>
using namespace std;
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 100005;
char s[N];
int sum[N], p[N];
long long ans[N];
int main() {
	int T, n, k, q;
	read(T);
	while (T--) {
		read(n), read(k), read(q);
		scanf("%s", s + 1);
		sum[0] = 0;
		for (int i = 1; i <= n; ++i) {
			if (s[i] == '0')	sum[i] = sum[i - 1] + 1;
			else sum[i] = sum[i - 1];
		}
		for (int i = 1; i <= n; ++i) {
			int l = i, r = min(n, i + 2 * k - 1), now = l;
			while (l <= r) {
				int mid = l + r >> 1;
				int tot = mid - i + 1;
				int t = sum[mid] - sum[i - 1]; //0
				if (t <= k && tot - t <= k)	{
					now = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			p[i] = now;
			ans[i] = now - i + 1;
		}
		ans[0] = 0;
		for (int i = 1; i <= n; ++i)	ans[i] += ans[i - 1];
		while (q--) {
			int L, R;
			read(L), read(R);
			int l = L, r = R, now = L - 1;
			while (l <= r) {
				int mid = l + r >> 1;
				if (p[mid] <= R)	now = mid, l = mid + 1;
				else r = mid - 1;
			}
			int t = R - now;
			printf("%lld\n", ans[now] - ans[L - 1] + (long long)t * (t + 1) / 2);
		}
	}
	return 0;
}
