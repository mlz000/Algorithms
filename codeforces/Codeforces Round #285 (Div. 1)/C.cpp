#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
int n, a[N], cnt[N];
inline bool in(int k, int i, int j) {
	return i <= k && k <= j;
}
bool check(int l, int r) {
	for (int i = 1; i <= n; ++i)	cnt[i] = 0;
	for (int i = l; i <= r; ++i)	++cnt[a[i]];
	for (int i = 1; i <= n; ++i) {
		if (!in(i, l, r) && !in(n - i + 1, l, r) && a[i] != a[n - i + 1])	return 0;
		if (!in(i, l, r) && in(n - i + 1, l, r))	--cnt[a[i]];
	}
	for (int i = 1; i <= n; ++i)	
		if (cnt[a[i]] < 0)	return 0;
	return 1;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]), ++cnt[a[i]];
	int s = 0;
	for (int i = 1; i <= n; ++i)	s += cnt[i] & 1;
	if (s > 1)	{
		puts("0");	
		return 0;
	}
	long long ans = 0ll;
	int p = 1;
	while (a[p] == a[n - p + 1])	++p;
	if (p >= n)	printf("%I64d\n", (LL)n * (n + 1) / 2);
	else {
		int l = p, r = n - l + 1;
		while (l < r - 1) {
			int mid = l + r >> 1;
			if (check(p, mid))	r = mid;
			else l = mid;
		}
		ans += (LL)p * (n - r + 1);
		reverse(a + 1, a + n + 1);
		l = p, r = n - l + 1;
		while (l < r - 1) {
			int mid = l + r >> 1;
			if (check(p, mid))	r = mid;
			else l = mid;
		}
		ans += (LL)p * (n - p - r + 1);
		printf("%I64d\n", ans);
	}
	return 0;
}
