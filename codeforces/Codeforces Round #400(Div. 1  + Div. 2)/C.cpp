#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 5;
const LL inf = 1e14;
int a[N];
LL p[50];
map<LL, int> mp;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
	int cnt = 0;
	p[0] = 1;
	if (k == -1 || k == 1) {
		if (k == -1)	p[++cnt] = k;
	}
	else {
		LL now = 1;
		while (abs(now * k) <= inf) {
			p[++cnt] = now * k;
			now *= k;
		}
	}
	for (int i = 0; i <= cnt; ++i)	++mp[p[i]];
	LL sum = 0, ans = 0;
	for (int i = 1; i <= n; ++i) {
		sum += a[i];
		ans += mp[sum];
		for (int j = 0; j <= cnt; ++j)	++mp[sum + p[j]];
	}
	printf("%I64d\n", ans);
	return 0;
}
